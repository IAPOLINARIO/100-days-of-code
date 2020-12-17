package main

import (
	"reflect"
	"testing"
)

func Test_100k_Fields(t *testing.T) {
	input := 1034000.
	expectedResult := 144818.00

	result := calcDeforestation(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_200k_Fields(t *testing.T) {
	input := 2034000.
	expectedResult := 284874.00

	result := calcDeforestation(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_4k_Fields(t *testing.T) {
	input := 34000.
	expectedResult := 4762.00

	result := calcDeforestation(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
