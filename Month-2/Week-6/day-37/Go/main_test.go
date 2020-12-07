package main

import (
	"reflect"
	"testing"
)

func Test_4_2(t *testing.T) {
	input := []int{10, 5, 20, 20, 4, 5, 2, 25, 1}
	expectedResult := "[2,4]"

	result := breakingRecords(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_5_3(t *testing.T) {
	input := []int{10, 5, 20, 20, 4, 5, 2, 25, 1, 0, 29}
	expectedResult := "[3,5]"

	result := breakingRecords(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_1_1(t *testing.T) {
	input := []int{10, 5, 25}
	expectedResult := "[1,1]"

	result := breakingRecords(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
