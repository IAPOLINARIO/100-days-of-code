package main

import (
	"reflect"
	"testing"
)

func Test_Repeated_String_1(t *testing.T) {
	input := []string{"aaaaaa", "bc", "d", "eeee", "xyz"}
	expectedResult := []string{"aaaaaa", "d", "eeee"}

	result := identicalFilter(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Repeated_String_2(t *testing.T) {
	input := []string{"88", "999", "22", "545", "133"}
	expectedResult := []string{"88", "999", "22"}

	result := identicalFilter(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Repeated_String_3(t *testing.T) {
	input := []string{"xxxxo", "oxo", "xox", "ooxxoo", "oxo"}
	expectedResult := 0

	result := len(identicalFilter(input))

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
