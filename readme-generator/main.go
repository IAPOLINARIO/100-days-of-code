package main

import (
	"encoding/json"
	"fmt"
	"io/ioutil"
	"log"
	"net/http"
	"os"
	"regexp"

	"github.com/IAPOLINARIO/100-days-of-code/readme-generator/structs"
)

const (
	baseGithubURI    = "https://api.github.com"
	collaboratorsURI = "/repos/IAPOLINARIO/100-days-of-code/collaborators"
	commitsURI       = "/repos/IAPOLINARIO/100-days-of-code/commits"
	eventsURI        = "/repos/IAPOLINARIO/100-days-of-code/events"
	pullRequestsURI  = "/repos/IAPOLINARIO/100-days-of-code/pulls?state=closed"
)

func main() {
	token := os.Args[1]

	//getCollaboratorStats(token)
	//getCommits(token)
	getPullRequests(token)
}

func getGithubAPIResult(repoUrl string, token string) ([]byte, error) {
	// Create a token string by appending string access token
	var bearer = "token  " + token

	client := &http.Client{}
	req, _ := http.NewRequest("GET", repoUrl, nil)
	req.Header.Add("Authorization", bearer)

	resp, err := client.Do(req)

	if err != nil {
		log.Fatalln(err)
	}

	defer resp.Body.Close()

	return ioutil.ReadAll(resp.Body)
}

func getCollaboratorStats(token string) {

	bodyBytes, _ := getGithubAPIResult(baseGithubURI+collaboratorsURI, token)
	// Convert response body to Contributors
	var contributors []structs.Contributor
	json.Unmarshal(bodyBytes, &contributors)

	fmt.Printf("Contributors on this repo:\n")
	for _, contr := range contributors {
		fmt.Printf("%v \n", contr.Login)
	}

	//fmt.Printf("API Response as struct %+v\n", todoStruct)
}

func getCommits(token string) {
	bodyBytes, _ := getGithubAPIResult(baseGithubURI+commitsURI, token)

	var commitBody []structs.Commit_Body
	json.Unmarshal(bodyBytes, &commitBody)

	fmt.Printf("Latest Commits:\n")
	for _, c := range commitBody {
		fmt.Printf("Author: %v\n", c.Author.Login)

		getcommit(token, c.Sha)
	}
	//bodyString := string(bodyBytes)
	//fmt.Println("API Response as String:\n" + bodyString)

}

func getcommit(token string, id string) {
	commitURI := baseGithubURI + commitsURI + "/" + id
	bodyBytes, _ := getGithubAPIResult(commitURI, token)

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
	bodyBytes, _ := getGithubAPIResult(baseGithubURI+eventsURI, token)
	fmt.Printf("Latest Events:\n")

	bodyString := string(bodyBytes)
	fmt.Println("API Response as String:\n" + bodyString)

}

func getPullRequests(token string) {
	bodyBytes, _ := getGithubAPIResult(baseGithubURI+pullRequestsURI, token)

	var PRs []structs.PullRequest
	json.Unmarshal(bodyBytes, &PRs)

	fmt.Printf("These are the pull requests:\n")
	for _, p := range PRs {
		fmt.Printf("PR: %v - Body: %v - Author: %v \n", p.Title, p.Body, p.User.Login)
	}

}
