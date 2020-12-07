package main

import (
	"reflect"
	"testing"
)

func Test_6_Games(t *testing.T) {
	expectedResult := 6

	result := howManyGames(20, 3, 6, 80)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_7_Games(t *testing.T) {
	expectedResult := 7

	result := howManyGames(20, 3, 6, 90)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_40_Games(t *testing.T) {
	expectedResult := 40

	result := howManyGames(50, 10, 5, 500)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_34_Games(t *testing.T) {
	expectedResult := 34

	result := howManyGames(20, 10, 3, 355)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
