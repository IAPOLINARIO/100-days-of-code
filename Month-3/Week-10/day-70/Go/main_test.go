package main

import (
	"reflect"
	"testing"
)

func Test_Word_1(t *testing.T) {
	brokenKeyboard := "abcd"

	expectedResult := "abaca"

	result := longestWord(brokenKeyboard)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Word_2(t *testing.T) {
	brokenKeyboard := "edcf"

	expectedResult := "deeded"

	result := longestWord(brokenKeyboard)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Word_3(t *testing.T) {
	brokenKeyboard := "bnik"

	expectedResult := "bikini"

	result := longestWord(brokenKeyboard)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Word_4(t *testing.T) {
	brokenKeyboard := "poil"

	expectedResult := "lollipop"

	result := longestWord(brokenKeyboard)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
