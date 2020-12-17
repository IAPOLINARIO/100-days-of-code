package main

import (
	"reflect"
	"testing"
)

func Test_5_15(t *testing.T) {
	input_h := 5
	input_m := 15
	expectedResult := "Quarter past five"

	result := timeInWords(input_h, input_m)
	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_6_30(t *testing.T) {
	input_h := 6
	input_m := 30
	expectedResult := "Half past six"

	result := timeInWords(input_h, input_m)
	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_7_00(t *testing.T) {
	input_h := 7
	input_m := 00
	expectedResult := "seven o' clock"

	result := timeInWords(input_h, input_m)
	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_4_45(t *testing.T) {
	input_h := 4
	input_m := 45
	expectedResult := "Quarter to five"

	result := timeInWords(input_h, input_m)
	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
