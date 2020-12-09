package main

import (
	"reflect"
	"testing"
)

func Test_Area_3(t *testing.T) {
	base := 3
	height := 2
	expectedResult := 3

	result := triArea(base, height)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Area_10(t *testing.T) {
	base := 5
	height := 4
	expectedResult := 10

	result := triArea(base, height)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Area_14(t *testing.T) {
	base := 7
	height := 4
	expectedResult := 14

	result := triArea(base, height)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Area_50(t *testing.T) {
	base := 10
	height := 10
	expectedResult := 50

	result := triArea(base, height)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
