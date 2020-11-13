package main

import (
	"testing"
)

func TestMergeArray_1(t *testing.T) {
	array_1 := "[1,2,3,0,0,0]"
	array_2 := "[2,5,6]"
	expectedResult := "[1,2,2,3,5,6]"

	result, _ := MergeArrays(array_1, array_2)

	if result != expectedResult {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func TestMergeArray_2(t *testing.T) {
	array_1 := "[1,2,3,4,5,0,0,0]"
	array_2 := "[2,5,6]"
	expectedResult := "[1,2,2,3,4,5,5,6]"

	result, _ := MergeArrays(array_1, array_2)

	if result != expectedResult {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func TestMergeArray_3(t *testing.T) {
	array_1 := "[1,2,3,4,0,0,0]"
	array_2 := "[2,5,6]"
	expectedResult := "[1,2,2,3,4,5,6]"

	result, _ := MergeArrays(array_1, array_2)

	if result != expectedResult {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func TestMergeArray_6(t *testing.T) {
	array_1 := "[4,5,6,8,9,10,0,0,0]"
	array_2 := "[4,5,6]"
	expectedResult := "[4,4,5,5,6,6,8,9,10]"

	result, _ := MergeArrays(array_1, array_2)

	if result != expectedResult {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func TestMergeArray_7(t *testing.T) {
	array_1 := "[4,5,6,7,8,9,10,0,0,0]"
	array_2 := "[4,5,6]"
	expectedResult := "[4,4,5,5,6,6,7,8,9,10]"

	result, _ := MergeArrays(array_1, array_2)

	if result != expectedResult {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
