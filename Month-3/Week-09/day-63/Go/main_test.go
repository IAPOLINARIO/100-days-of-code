package main

import (
	"reflect"
	"testing"
)

func Test_32_Weeks(t *testing.T) {
	input := []float64{2, 4, 1000000000}
	expectedResult := float64(32)

	result, _ := rabbitSwarm(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_36_Weeks(t *testing.T) {
	input := []float64{2, 4, 15000000000}
	expectedResult := float64(36)

	result, _ := rabbitSwarm(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
