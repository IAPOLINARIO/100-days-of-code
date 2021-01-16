package main

import (
	"github.com/dghubble/go-twitter/twitter"
	"github.com/dghubble/oauth1"
)

func main() {
	config := oauth1.NewConfig("consumerKey", "consumerSecret")
	token := oauth1.NewToken("accessToken", "accessSecret")
	httpClient := config.Client(oauth1.NoContext, token)

	// Twitter client
	client := twitter.NewClient(httpClient)

	// Home Timeline
	tweets, resp, err := client.Timelines.HomeTimeline(&twitter.HomeTimelineParams{
		Count: 20,
	})

}
