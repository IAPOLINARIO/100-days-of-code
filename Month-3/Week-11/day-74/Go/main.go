package main

import (
	"flag"
	"fmt"
	"os"
	"strconv"
	"strings"
	"time"

	"github.com/dghubble/go-twitter/twitter"
	"golang.org/x/oauth2"
	"golang.org/x/oauth2/clientcredentials"
)

type Cattle struct {
	TwitterUser *twitter.User
	Tweets      []twitter.Tweet
	score       int
}

func NewCattle(tw *twitter.User, tm []twitter.Tweet) *Cattle {
	var c = new(Cattle)
	c.TwitterUser = tw
	c.Tweets = tm

	//Offical Account (verified by twitter)
	if c.TwitterUser.Verified {
		c.score--
	}

	//No Bio
	if c.TwitterUser.DefaultProfile {
		c.score++
	}

	//An Egghead
	if c.TwitterUser.DefaultProfileImage {
		c.score++
	}

	//No Bio
	if c.TwitterUser.Description == "" {
		c.score++
	}

	// Keywords for bots
	if strings.ContainsAny(strings.Join(keyCattleWords, ""), c.TwitterUser.Name) {
		c.score++
	}

	//Follows 2,001 People
	if c.TwitterUser.FriendsCount == 2001 {
		c.score++
	}

	// To little followers
	if c.TwitterUser.FollowersCount <= 50 || c.TwitterUser.FriendsCount <= 50 {
		c.score++
	}

	//No interaction
	if c.TwitterUser.FavouritesCount < 100 {
		c.score++
	}

	//Excessive Duplicate Tweets
	if c.Tweets[0].Text == c.Tweets[1].Text {
		c.score++
	}

	//Has Not Tweeted in Years
	tweetYear, _ := strconv.Atoi(strings.Split(c.Tweets[0].CreatedAt, " ")[5]) //format: Sun Jan 17 17:17:49 +0000 2021
	if tweetYear < time.Now().Year() {
		c.score++
	}

	//An Unrealistic Amount of Tweets
	if len(c.Tweets) >= 200 {
		c.score++
	}

	return c
}

var (
	keyCattleWords = []string{"patriota", "bolsonaro", "direita", "familia", "usa", "bolsonarista", "17", "mito"}
)

func main() {

	clientId := flag.String("client-id", "", "Twitter client id")
	clientSecret := flag.String("client-secret", "", "Twitter client secret")
	twitterHandle := flag.String("twitter-handle", "", "Twitter account to perform the checks")

	flag.Parse()

	result := checkCattleLevel(clientId, clientSecret, twitterHandle)

	fmt.Printf("Result: %v \n", result)

}

func ScoreBuild(clientId *string, clientSecret *string, twitterHandle *string) int {
	// oauth2 configures a client that uses app credentials to keep a fresh token
	config := &clientcredentials.Config{
		ClientID:     *clientId,
		ClientSecret: *clientSecret,
		TokenURL:     "https://api.twitter.com/oauth2/token",
	}
	// http.Client will automatically authorize Requests
	httpClient := config.Client(oauth2.NoContext)

	// Twitter client
	client := twitter.NewClient(httpClient)

	// User Show
	user, _, err := client.Users.Show(&twitter.UserShowParams{
		ScreenName: *twitterHandle,
	})

	if err != nil {
		fmt.Println("Error")
		os.Exit(1)
	}

	tweets, _, err := client.Timelines.UserTimeline(&twitter.UserTimelineParams{
		ScreenName:      *twitterHandle,
		IncludeRetweets: twitter.Bool(true),
		Count:           200,
	})

	if err != nil {
		fmt.Println("Error")
		os.Exit(1)
	}

	cattle := NewCattle(user, tweets)

	fmt.Printf("Twitter: %v - %v \n", cattle.TwitterUser.Name, cattle.TwitterUser.Description)
	fmt.Printf("Account created at: %v \n", cattle.TwitterUser.CreatedAt)
	fmt.Printf("Number of tweets: %v \n", len(cattle.Tweets))
	fmt.Printf("Email: %v \n", len(cattle.TwitterUser.Email))

	return cattle.score * 10
}

func checkCattleLevel(clientId *string, clientSecret *string, twitterHandle *string) string {
	switch score := ScoreBuild(clientId, clientSecret, twitterHandle); {
	case score <= 20:
		return "Not a cattle"
	case score >= 21 && score <= 80:
		return "Sounds like a cattle (muhhhh)"
	case score >= 81:
		return "Too much cattle! 🐮"
	}
	return ""
}
