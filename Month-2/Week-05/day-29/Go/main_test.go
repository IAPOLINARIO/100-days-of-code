package main

import (
	"reflect"
	"strings"
	"testing"
)

func Test_ACCEPT(t *testing.T) {
	input := "R G Y R C R G Y R"
	expectedResult := "CORRECT"

	result := trafficLightChecker(strings.Split(input, " "))

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_REJECT(t *testing.T) {
	input := "G Y R G Y R"
	expectedResult := "REJECT"

	result := trafficLightChecker(strings.Split(input, " "))

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_ERROR_UNDEFINED(t *testing.T) {
	input := "R 8 S"
	expectedResult := "ERROR"

	result := trafficLightChecker(strings.Split(input, " "))

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_ERROR_TO_LONG(t *testing.T) {
	input := "R G Y R G Y R G Y C X R G Y R G Y"
	expectedResult := "REJECT"

	result := trafficLightChecker(strings.Split(input, " "))

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
