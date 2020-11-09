package main

import (
	"reflect"
	"testing"
)

func Test_Car_Anagram(t *testing.T) {
	inputWordOne := "car"
	inputWordTwo := "rac"
	expectedResult := true

	result := IsAnagram(inputWordOne, inputWordTwo)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Anagram_Anagram(t *testing.T) {
	inputWordOne := "anagram"
	inputWordTwo := "nagaram"
	expectedResult := true

	result := IsAnagram(inputWordOne, inputWordTwo)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Anagram_Ismael(t *testing.T) {
	inputWordOne := "ismael"
	inputWordTwo := "bolsominion"
	expectedResult := false

	result := IsAnagram(inputWordOne, inputWordTwo)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Anagram_Canova(t *testing.T) {
	inputWordOne := "canova"
	inputWordTwo := "gamer"
	expectedResult := false

	result := IsAnagram(inputWordOne, inputWordTwo)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Anagram_Banana(t *testing.T) {
	inputWordOne := "banana"
	inputWordTwo := "nanaba"
	expectedResult := true

	result := IsAnagram(inputWordOne, inputWordTwo)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
