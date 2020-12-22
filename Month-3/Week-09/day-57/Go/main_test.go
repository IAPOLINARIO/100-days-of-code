package main

import (
	"reflect"
	"testing"
)

func Test_Sigilize_1(t *testing.T) {
	input := "i am healthy"
	expectedResult := "MLTHY"

	result := sigilize(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Sigilize_2(t *testing.T) {
	input := "I FOUND MY SOULMATE"
	expectedResult := "FNDYSLMT"

	result := sigilize(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Sigilize_3(t *testing.T) {
	input := "I have a job I enjoy and it pays well"
	expectedResult := "HVBJNDTPYSWL"

	result := sigilize(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
