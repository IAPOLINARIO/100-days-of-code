package main

import (
	"reflect"
	"testing"
)

func Test_G1(t *testing.T) {
	url := "https://g1.globo.com/"
	depth := 1
	expectedResult := true

	Crawl(url, depth)
	result := results.Exists("http://g1.globo.com")

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Google(t *testing.T) {
	url := "https://google.com"
	depth := 1
	expectedResult := true

	Crawl(url, depth)
	result := results.Exists("https://mail.google.com/mail/?tab=wm")

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Youtube(t *testing.T) {
	url := "https://youtube.com"
	depth := 1
	expectedResult := true

	Crawl(url, depth)
	result := results.Exists("https://www.youtube.com/about/")

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
