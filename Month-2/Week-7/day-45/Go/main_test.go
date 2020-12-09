package main

import (
	"reflect"
	"testing"
)

func Test_31(t *testing.T) {
	x := 10
	y := 41
	expectedResult := 31

	result := XOR(x, y)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_351(t *testing.T) {
	x := 69
	y := 420
	expectedResult := 351

	result := XOR(x, y)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_1(t *testing.T) {
	x := 2
	y := 1
	expectedResult := -1

	result := XOR(x, y)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
