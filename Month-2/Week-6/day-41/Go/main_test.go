package main

import (
	"reflect"
	"testing"
)

func Test_0_Pairs(t *testing.T) {
	input := []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 0}
	expectedResult := 0

	result := sockPairs(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
func Test_1_Pairs(t *testing.T) {
	input := []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 1}
	expectedResult := 1

	result := sockPairs(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
func Test_2_Pairs(t *testing.T) {
	input := []int{1, 2, 1, 2, 1, 3, 2}
	expectedResult := 2

	result := sockPairs(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_6_Pairs(t *testing.T) {
	input := []int{1, 2, 1, 7, 2, 7, 1, 3, 2, 5, 2, 3, 5, 7}
	expectedResult := 6

	result := sockPairs(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_4_Pairs(t *testing.T) {
	input := []int{2, 7, 2, 1, 3, 5, 2, 3, 5, 7}
	expectedResult := 4

	result := sockPairs(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_5_Pairs(t *testing.T) {
	input := []int{2, 7, 2, 1, 3, 8, 5, 2, 3, 5, 7, 8}
	expectedResult := 5

	result := sockPairs(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
