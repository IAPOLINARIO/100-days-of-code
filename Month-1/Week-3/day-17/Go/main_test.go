package main

import (
	"reflect"
	"testing"
)

func Test_Four_Prisioners(t *testing.T) {
	input := []int{1, 1, 0, 0, 0, 1, 0}
	expectedResult := 4

	result := freedPrisioner(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_One_Prisioner(t *testing.T) {
	input := []int{1, 1, 1}
	expectedResult := 1

	result := freedPrisioner(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Zero_Prisioners(t *testing.T) {
	input := []int{0, 1, 1}
	expectedResult := 0

	result := freedPrisioner(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Five_Prisioners(t *testing.T) {
	input := []int{1, 1, 0, 0, 0, 1, 0, 1}
	expectedResult := 5

	result := freedPrisioner(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Eight_Prisioners(t *testing.T) {
	input := []int{1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0}
	expectedResult := 8

	result := freedPrisioner(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
