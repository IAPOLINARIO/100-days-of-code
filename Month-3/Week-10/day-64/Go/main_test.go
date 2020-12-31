package main

import (
	"reflect"
	"testing"
)

func Test_Recurrence_A(t *testing.T) {
	input := "ABCDEABC"
	expectedResult := "A"

	result := checkRecurrence(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Recurrence_B(t *testing.T) {
	input := "ABCDEBC"
	expectedResult := "B"

	result := checkRecurrence(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Recurrence_C(t *testing.T) {
	input := "CACDEBC"
	expectedResult := "C"

	result := checkRecurrence(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Recurrence_D(t *testing.T) {
	input := "DACDEBC"
	expectedResult := "D"

	result := checkRecurrence(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
