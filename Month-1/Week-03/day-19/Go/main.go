package main

import (
	"fmt"
	"math/rand"
	"net/url"
)

func main() {
	result, _ := ShortMyUrl("https://bing.com/search", "isma.me")

	fmt.Printf(result)
}

func ShortMyUrl(myUrl string, customShortLink string) (result string, err error) {

	u, err := url.Parse(myUrl)
	if err != nil {
		return "", err
	}

	result = fmt.Sprintf("%v://%v/%v", u.Scheme, customShortLink, RandomString(8, u.Host+u.Path))
	return result, err
}

func RandomString(n int, characters string) string {
	var letters = []rune(characters)

	s := make([]rune, n)
	for i := range s {
		s[i] = letters[rand.Intn(len(letters))]
	}

	return string(s)
}
