package main

import (
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
)

func main() {
	token := os.Args[1]
	PRs := getPullRequests(token)

	buildOutputResult(PRs)
}

func getGithubAPIResult(repoUrl string, token string) (*http.Response, error) {
	// Create a token string by appending string access token
	var bearer = "token  " + token

	client := &http.Client{}
	req, _ := http.NewRequest("GET", repoUrl, nil)
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

func buildOutputResult(PRs []structs.PullRequest) {
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

	sortedMap := SortMapByValue(req)
	filecontent := getTemplateFile()
	rankingTable := buildRankingTable(sortedMap)
	updatedReadme := strings.Replace(filecontent, rankingToken, rankingTable, 1)
	updatedReadme = strings.Replace(updatedReadme, updateToken, time.Now().String(), 1)

	writeReadme(updatedReadme)
	fmt.Println(updatedReadme)

	//buildRankingTable(&sortedMap)
}

func buildRankingTable(sortedMap map[string][]string) string {
	//table := tablewriter.NewWriter(os.Stdout)
	tableString := &strings.Builder{}
	table := tablewriter.NewWriter(tableString)
	emojiList := []string{":worried:", ":confused:", ":star2:", ":sweat_drops:", ":no_good:", ":older_man:", ":guardsman:", ":hear_no_evil:", ":see_no_evil:", ":speak_no_evil:", ":cool:", ":small_red_triangle_down:", ":cookie:", ":hamburger:", ":floppy_disk:", ":ghost:", ":snail:", ":zap:", ":poop:", ":imp:"}

	table.SetHeader([]string{"Ranking", "Contributor", "Challenges Completed", "Total Points"})
	table.SetBorders(tablewriter.Border{Left: true, Top: false, Right: true, Bottom: false})
	table.SetCenterSeparator("|")

	fmt.Printf("Number of participants: %v \n", len(sortedMap))
	for k, v := range sortedMap {
		ranking := v[0]
		contributor := "[" + k + "](" + "https://github.com/" + k + ")"
		challengesCompleted := v[1]
		totalPoints := v[2]

		if ranking == "1" {
			ranking = ":trophy:" + " " + ranking
		} else if ranking == "2" {
			ranking = ":2nd_place_medal:" + " " + ranking
		} else if ranking == "3" {
			ranking = ":3rd_place_medal:" + " " + ranking
		} else {
			randomIndex := rand.Intn(len(emojiList))
			emoji := emojiList[randomIndex]
			ranking = emoji + " " + ranking
		}

		result := []string{ranking, contributor, challengesCompleted, totalPoints}
		table.Append(result)
	}

	table.Render()

	return tableString.String()
}

func SortMapByValue(Map map[string][]string) map[string][]string {

	resultMap := make(map[string][]string)
	// used to switch key and value
	hack := map[float64][]string{}
	hackkeys := []float64{}

	for key, val := range Map {
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
