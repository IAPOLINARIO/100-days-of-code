package main

import (
	"bufio"
	"encoding/json"
	"fmt"
	"io/ioutil"
	"log"
	"math/rand"
	"net/http"
	"os"
	"regexp"
	"sort"
	"strconv"
	"strings"
	"time"

	"github.com/IAPOLINARIO/100-days-of-code/readme-generator/structs"
	"github.com/olekukonko/tablewriter"
)

//const variables
const (
	baseGithubURI    = "https://api.github.com"
	collaboratorsURI = "/repos/IAPOLINARIO/100-days-of-code/collaborators"
	commitsURI       = "/repos/IAPOLINARIO/100-days-of-code/commits"
	eventsURI        = "/repos/IAPOLINARIO/100-days-of-code/events"
	pullRequestsURI  = "/repos/IAPOLINARIO/100-days-of-code/pulls?state=closed"
	templatePath     = "./static-README.md"
	rankingToken     = "##RANKING_TOKEN##"
	updateToken      = "##LATEST_UPDATED##"
	ReadmePath       = "../README.md"
	indexToken       = "##INDEX_TOKEN##"
)

func main() {
	token := os.Args[1]
	PRs := getPullRequests(token)

	updatedReadme := buildOutputResult(PRs)
	indexUpdated := buildChallengeIndex()
	updatedReadmeWithIndex := strings.Replace(updatedReadme, indexToken, strings.Join(indexUpdated, " "), 1)

	writeReadme(updatedReadmeWithIndex)
	fmt.Println(updatedReadmeWithIndex)

}

func buildChallengeIndex() (result []string) {
	baseDir := "../"
	monthFolders, _ := ioutil.ReadDir(baseDir)

	for _, mFolder := range monthFolders {
		if strings.Contains(mFolder.Name(), "Month-") {
			//fmt.Println(mFolder.Name())
			monthDir := baseDir + mFolder.Name() + "/"
			weekFolders, _ := ioutil.ReadDir(monthDir)
			for _, wFolder := range weekFolders {
				if strings.Contains(wFolder.Name(), "Week-") {
					weekLinkToAppend := fmt.Sprintf("[%v](https://github.com/IAPOLINARIO/100-days-of-code/tree/main/%v/%v) <br/>", wFolder.Name(), mFolder.Name(), wFolder.Name())

					result = append(result, weekLinkToAppend)
					weekDir := monthDir + wFolder.Name() + "/"
					dayFolders, _ := ioutil.ReadDir(weekDir)
					for _, dFolder := range dayFolders {
						if strings.Contains(dFolder.Name(), "day-") {
							solvedWith := ""
							languagesDir := weekDir + dFolder.Name() + "/"
							languagesFolders, _ := ioutil.ReadDir(languagesDir)

							for i, lFolder := range languagesFolders {
								if lFolder.Name() != "README.md" {
									techToAppend := fmt.Sprintf("[%v](https://github.com/IAPOLINARIO/100-days-of-code/tree/main/%v/%v/%v/%v)", lFolder.Name(), mFolder.Name(), wFolder.Name(), dFolder.Name(), lFolder.Name())
									solvedWith += techToAppend

									if i < len(languagesFolders)-1 {
										solvedWith += ", "
									}
								}
							}
							//fmt.Println("---" + dFolder.Name())
							filePath := weekDir + dFolder.Name() + "/README.md"
							//fmt.Println("filepath: " + filePath)
							f, err := os.Open(filePath)
							if err != nil {
								log.Fatalln(err)
							}
							defer f.Close()
							scanner := bufio.NewScanner(f)
							var line int
							for scanner.Scan() {
								if line == 0 {
									challengeTitle := strings.Replace(scanner.Text(), "#", "", 2)
									challengeToAppend := fmt.Sprintf("[%v -%v](https://github.com/IAPOLINARIO/100-days-of-code/blob/main/%v/%v/%v/README.md)", dFolder.Name(), challengeTitle, mFolder.Name(), wFolder.Name(), dFolder.Name())
									if solvedWith != "" {
										result = append(result, fmt.Sprintf("&nbsp;&nbsp;&nbsp;&nbsp;%v - [Already solved with %v] <br/>", challengeToAppend, solvedWith))
									} else {
										result = append(result, fmt.Sprintf("&nbsp;&nbsp;&nbsp;&nbsp;%v - Not Solved yet <br/>", challengeToAppend))
									}
								}
								line++
								break
							}

							if err := scanner.Err(); err != nil {
								log.Fatalln(err)
							}

						}
					}

				}
			}

		}
	}
	return
}

//getGithubAPIResult get results from github
func getGithubAPIResult(repoURL string, token string) (*http.Response, error) {
	// Create a token string by appending string access token
	var bearer = "token  " + token

	client := &http.Client{}
	req, _ := http.NewRequest("GET", repoURL, nil)
	req.Header.Add("Authorization", bearer)

	resp, err := client.Do(req)

	if err != nil {
		log.Fatalln(err)
	}

	return resp, err
}

func getCollaboratorStats(token string) {

	resp, _ := getGithubAPIResult(baseGithubURI+collaboratorsURI, token)
	bodyBytes, _ := ioutil.ReadAll(resp.Body)

	// Convert response body to Contributors
	var contributors []structs.Contributor

	json.Unmarshal(bodyBytes, &contributors)

	fmt.Printf("Contributors on this repo:\n")
	for _, contr := range contributors {
		fmt.Printf("%v \n", contr.Login)
	}

}

func getCommits(token string) {

	resp, _ := getGithubAPIResult(baseGithubURI+commitsURI, token)
	bodyBytes, _ := ioutil.ReadAll(resp.Body)

	var commitBody []structs.Commit_Body
	json.Unmarshal(bodyBytes, &commitBody)

	fmt.Printf("Latest Commits:\n")
	for _, c := range commitBody {
		fmt.Printf("Author: %v\n", c.Author.Login)

		getcommit(token, c.Sha)
	}
}

func getcommit(token string, id string) {
	commitURI := baseGithubURI + commitsURI + "/" + id
	resp, _ := getGithubAPIResult(commitURI, token)
	bodyBytes, _ := ioutil.ReadAll(resp.Body)

	var commit structs.Commit_Body
	json.Unmarshal(bodyBytes, &commit)

	//fmt.Printf("Files changed in this commit: %v, Total changes: %v\n", len(commit.Files), commit.Stats.Total)
	for _, f := range commit.Files {
		//   \b(\w*day-\w*)\b     			-> match whole word

		rg := regexp.MustCompile("day-\\w*")
		match := rg.FindStringSubmatch(f.Filename)

		if len(match) > 0 {
			fmt.Printf("Challenge of day: %v was solved \n", match[0])
		}
	}

}

func getEvents(token string) {
	resp, _ := getGithubAPIResult(baseGithubURI+eventsURI, token)
	bodyBytes, _ := ioutil.ReadAll(resp.Body)

	fmt.Printf("Latest Events:\n")

	bodyString := string(bodyBytes)
	fmt.Println("API Response as String:\n" + bodyString)

}

func buildOutputResult(PRs []structs.PullRequest) string {
	req := make(map[string][]string)
	for i := 0; i < len(PRs); i++ {
		challengesDone := ""
		totalPoints := 0
		userHasDoneLabel := false

		for _, l := range PRs[i].Labels {
			if l.Name == "done" {
				rg := regexp.MustCompile("day-\\w*")
				match := rg.FindStringSubmatch(PRs[i].Title)

				if len(match) > 0 {
					userHasDoneLabel = true
					if !strings.Contains(challengesDone, match[0]) {
						challengesDone = match[0]
						totalPoints += 100
					}
				}
			}
		}

		if userHasDoneLabel {
			if len(req[PRs[i].User.Login]) > 0 {
				currentUserValue := req[PRs[i].User.Login]
				challengesCombined := []string{currentUserValue[0], challengesDone}
				currentTotalScore, _ := strconv.Atoi(currentUserValue[1])
				newScore := totalPoints + currentTotalScore
				req[PRs[i].User.Login] = []string{strings.Join(challengesCombined, ","), strconv.Itoa(newScore)}

			} else {
				req[PRs[i].User.Login] = []string{challengesDone, strconv.Itoa(totalPoints)}
			}
		}

	}

	filecontent := getTemplateFile()
	filtered := SortMapByValue(&req)
	rankingTable := buildRankingTable(filtered)
	updatedReadme := strings.Replace(filecontent, rankingToken, rankingTable, 1)
	updatedReadme = strings.Replace(updatedReadme, updateToken, time.Now().String(), 1)

	return updatedReadme
}

func buildRankingTable(sortedMap map[string][]string) string {
	tableString := &strings.Builder{}
	orderedRanking := make(map[int][]string)

	table := tablewriter.NewWriter(tableString)
	emojiList := []string{":worried:", ":confused:", ":star2:", ":sweat_drops:", ":no_good:", ":older_man:", ":guardsman:", ":hear_no_evil:", ":see_no_evil:", ":speak_no_evil:", ":cool:", ":small_red_triangle_down:", ":cookie:", ":hamburger:", ":floppy_disk:", ":ghost:", ":snail:", ":zap:", ":poop:", ":imp:"}

	table.SetHeader([]string{"Ranking", "Contributor", "Challenges Completed", "Total Points"})
	table.SetBorders(tablewriter.Border{Left: true, Top: false, Right: true, Bottom: false})
	table.SetCenterSeparator("|")

	s1 := rand.NewSource(time.Now().UnixNano())
	r1 := rand.New(s1)

	for contributor, value := range sortedMap {
		//fmt.Printf("Item: %v\n", contributor)
		randomIndex := r1.Intn(len(emojiList))
		ranking := value[0]
		numberedRanking, _ := strconv.Atoi(ranking)

		//fmt.Printf("Ranking order: %v \n", ranking)
		contributor := "[" + contributor + "](" + "https://github.com/" + contributor + ")"
		challengesCompleted := value[1]
		totalPoints := value[2]

		if ranking == "1" {
			ranking = ":trophy:" + " " + ranking
		} else if ranking == "2" {
			ranking = ":2nd_place_medal:" + " " + ranking
		} else if ranking == "3" {
			ranking = ":3rd_place_medal:" + " " + ranking
		} else {
			emoji := emojiList[randomIndex]
			ranking = emoji + " " + ranking
		}

		orderedRanking[numberedRanking] = []string{ranking, contributor, challengesCompleted, totalPoints}
	}

	for i := 1; i <= len(orderedRanking); i++ {
		table.Append(orderedRanking[i])
	}

	//table.Append(result)

	table.Render()

	return tableString.String()
}

//SortMapByValue sort values by mapping
func SortMapByValue(Map *map[string][]string) map[string][]string {

	resultMap := make(map[string][]string)

	// used to switch key and value
	hack := map[float64][]string{}
	hackkeys := []float64{}

	for key, val := range *Map {
		NewKey, _ := strconv.ParseFloat(val[1], 64)
		NewValue := []string{key, val[0]}

		if len(hack[NewKey]) > 0 {
			NewKey += 0.00001
		}

		hackkeys = append(hackkeys, NewKey)

		hack[NewKey] = NewValue
	}

	sort.Slice(hackkeys, func(i, j int) bool {
		return hackkeys[i] >= hackkeys[j]
	})

	for i := 0; i < len(hackkeys); i++ {
		key := hack[hackkeys[i]][0]

		score := fmt.Sprintf("%.0f", hackkeys[i])
		value := []string{strconv.Itoa(i + 1), hack[hackkeys[i]][1], score}
		resultMap[key] = value
	}

	return resultMap
}

func getPullRequests(token string) []structs.PullRequest {
	var PRs []structs.PullRequest
	resp, _ := getGithubAPIResult(baseGithubURI+pullRequestsURI, token)
	bodyBytes, _ := ioutil.ReadAll(resp.Body)
	json.Unmarshal(bodyBytes, &PRs)

	links := strings.Split(resp.Header["Link"][0], ",")
	lastLink := links[1]

	rg := regexp.MustCompile("page=(\\d+)")
	match := rg.FindStringSubmatch(lastLink)

	totalPages, err := strconv.Atoi(match[1])

	if err != nil {
		panic(err)
	}

	for p := 2; p <= totalPages; p++ {
		newPRs := []structs.PullRequest{}
		respNextPage, _ := getGithubAPIResult(baseGithubURI+pullRequestsURI+"&page="+fmt.Sprint(p), token)
		bodyBytesNextPage, _ := ioutil.ReadAll(respNextPage.Body)
		json.Unmarshal(bodyBytesNextPage, &newPRs)
		PRs = append(PRs, newPRs...)
	}
	return PRs
}

func getTemplateFile() string {
	data, err := ioutil.ReadFile(templatePath)

	if err != nil {
		panic(err)
	}

	return string(data)
}

func writeReadme(fileContent string) {
	err := ioutil.WriteFile(ReadmePath, []byte(fileContent), 0)
	if err != nil {
		panic(err)
	}

	if err != nil {
		log.Fatalf("failed writing to file: %s", err)
	}
}
