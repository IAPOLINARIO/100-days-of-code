package main

import (
	"encoding/json"
	"fmt"
	"io/ioutil"
	"log"
	"net/http"
	"os"

	"github.com/IAPOLINARIO/100-days-of-code/readme-generator/structs"
)

const (
	baseGithubURI    = "https://api.github.com"
	collaboratorsURI = "/repos/IAPOLINARIO/100-days-of-code/collaborators"
)

func main() {
	arg := os.Args[1]

	getCollaboratorStats(arg)
}

func getGithubAPIResult(repoUrl string, token string) ([]byte, error) {
	fmt.Println("1. Performing Http Get...")

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

	// Convert response body to string
	//bodyString := string(bodyBytes)
	//fmt.Println("API Response as String:\n" + bodyString)

	return ioutil.ReadAll(resp.Body)
}

func getCollaboratorStats(token string) {

	bodyBytes, _ := getGithubAPIResult(baseGithubURI+collaboratorsURI, token)
	// Convert response body to Contributors
	var contributors []structs.Contributor
	json.Unmarshal(bodyBytes, &contributors)

	fmt.Printf("Contributors on this repo:\n")
	for _, c := range contributors {
		fmt.Printf("%v \n", c.Login)
	}

	//fmt.Printf("API Response as struct %+v\n", todoStruct)
}
