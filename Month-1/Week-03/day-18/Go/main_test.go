package main

import (
	"reflect"
	"testing"
)

func Test_28_Paths(t *testing.T) {
	input_m := 3
	input_n := 7
	expectedResult := 28

	result := uniquePaths(input_m, input_n)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_6_Paths(t *testing.T) {
	input_m := 3
	input_n := 3
	expectedResult := 6

	result := uniquePaths(input_m, input_n)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_3_Paths(t *testing.T) {
	input_m := 3
	input_n := 2
	expectedResult := 3

	result := uniquePaths(input_m, input_n)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_1352078_Paths(t *testing.T) {
	input_m := 12
	input_n := 13
	expectedResult := 1352078

	result := uniquePaths(input_m, input_n)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_70_Paths(t *testing.T) {
	input_m := 5
	input_n := 5
	expectedResult := 70

	result := uniquePaths(input_m, input_n)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_330_Paths(t *testing.T) {
	input_m := 8
	input_n := 5
	expectedResult := 330

	result := uniquePaths(input_m, input_n)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
