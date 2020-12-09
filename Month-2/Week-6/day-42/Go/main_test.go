package main

import (
	"reflect"
	"testing"
)

func Test_1_Page(t *testing.T) {
	expectedResult := 1.

	result := minPages(5, 3)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_5_Page(t *testing.T) {
	expectedResult := 5.

	result := minPages(50, 10)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_8_Page(t *testing.T) {
	expectedResult := 8.

	result := minPages(95, 16)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_225_Page(t *testing.T) {
	expectedResult := 225.

	result := minPages(1500, 450)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
