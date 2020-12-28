package main

import (
	"fmt"
	"log"
	"net/http"

	"github.com/PuerkitoBio/goquery"
)

type Result struct {
	urls []string
}

var results = new(Result)

// This will get called for each HTML element found
func processElement(index int, element *goquery.Selection) {
	// See if the href attribute exists on the element
	href, exists := element.Attr("href")
	if exists {
		if !results.Exists(href) {
			results.Add(href)
		}
	}
}

func (r *Result) Add(href string) {
	r.urls = append(r.urls, href)
}

func (r *Result) Exists(value string) bool {
	for _, url := range r.urls {
		if url == value {
			return true
		}
	}
	return false
}

func Crawl(url string, depth int) {

	if depth <= 0 {
		return
	}

	// Make HTTP request
	response, err := http.Get(url)
	if err != nil {
		return //log.Fatal(err)
	}
	defer response.Body.Close()

	// Create a goquery document from the HTTP response
	document, err := goquery.NewDocumentFromReader(response.Body)
	if err != nil {
		log.Fatal("Error loading HTTP response body. ", err)
	}

	// Find all links and process them with the function
	// defined earlier
	document.Find("a").Each(processElement)

	for _, u := range results.urls {
		go func(u string) {
			Crawl(u, depth-1)
		}(u)
	}
}

func main() {
	Crawl("https://youtube.com/", 1)

	for _, url := range results.urls {
		fmt.Println(url)
	}

	fmt.Printf("Total Results: %d", len(results.urls))
}
