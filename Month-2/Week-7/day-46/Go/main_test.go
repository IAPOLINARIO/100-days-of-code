package main

import (
	"reflect"
	"testing"
)

func Test_Avoid(t *testing.T) {
	inputPhrase := "vines that butter my eggroll"
	wordsToAvoid := []string{"anime", "meme", "vines", "roasts", "Danny DeVito"}
	expectedResult := "NO!"

	result := preventDistractions(inputPhrase, wordsToAvoid)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Avoid_Biroliro(t *testing.T) {
	inputPhrase := "I'm going to Brazil where the presidente is Bonoro"
	wordsToAvoid := []string{"tiros", "faria limers", "carnaval", "Biroliro", "Bonoro"}
	expectedResult := "NO!"

	result := preventDistractions(inputPhrase, wordsToAvoid)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Best_Lula(t *testing.T) {
	inputPhrase := "Lula is the best president ever!"
	wordsToAvoid := []string{"tiros", "faria limers", "carnaval", "Biroliro", "Bonoro"}
	expectedResult := "Safe watching!"

	result := preventDistractions(inputPhrase, wordsToAvoid)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
