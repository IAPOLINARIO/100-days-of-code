package main

import (
	"reflect"
	"testing"
)

func Test_Carry_3(t *testing.T) {
	input_1 := 555
	input_2 := 555
	expectedResult := 3

	result := carryOperations(input_1, input_2)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Carry_1(t *testing.T) {
	input_1 := 123
	input_2 := 594
	expectedResult := 1

	result := carryOperations(input_1, input_2)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Carry_0(t *testing.T) {
	input_1 := 1
	input_2 := 20000
	expectedResult := 0

	result := carryOperations(input_1, input_2)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
