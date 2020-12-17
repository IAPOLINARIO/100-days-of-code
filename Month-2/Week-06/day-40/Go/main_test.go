package main

import (
	"reflect"
	"testing"
)

func Test_True_1(t *testing.T) {
	input := []int{1, 6, 5, 2, 4, 3}
	expectedResult := true

	result := rotateArray(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_False_1(t *testing.T) {
	input := []int{6, 2, 1, 4, 3, 5}
	expectedResult := false

	result := rotateArray(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_False_2(t *testing.T) {
	input := []int{1, 7, 6, 5, 2, 4, 3}
	expectedResult := false

	result := rotateArray(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
