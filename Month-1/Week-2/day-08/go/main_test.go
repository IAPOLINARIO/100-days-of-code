package main

import (
	"reflect"
	"testing"
)

func Test_23_digits(t *testing.T) {
	input := "23"
	expectedResult := []string{"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"}

	result := letterCombinations(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_45_digits(t *testing.T) {
	input := "45"
	expectedResult := []string{"gj", "gk", "gl", "hj", "hk", "hl", "ij", "ik", "il"}

	result := letterCombinations(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
