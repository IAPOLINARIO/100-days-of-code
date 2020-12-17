package main

import (
	"reflect"
	"testing"
)

func Test_5_Combinations(t *testing.T) {
	input := 3
	expectedResult := 5

	result := len(buildTree(1, input))

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_2_Combinations(t *testing.T) {
	input := 2
	expectedResult := 2

	result := len(buildTree(1, input))

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_42_Combinations(t *testing.T) {
	input := 5
	expectedResult := 42

	result := len(buildTree(1, input))

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_4862_Combinations(t *testing.T) {
	input := 9
	expectedResult := 4862

	result := len(buildTree(1, input))

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
