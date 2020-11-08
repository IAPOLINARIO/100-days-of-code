package main

import (
	"reflect"
	"testing"
)

func Test_Apple(t *testing.T) {
	input := "apple"
	expectedResult := "1lpp0aca"

	result := Encrypt(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Ismael(t *testing.T) {
	input := "ismael"
	expectedResult := "l10ms2aca"

	result := Encrypt(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Banana(t *testing.T) {
	input := "banana"
	expectedResult := "0n0n0baca"

	result := Encrypt(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Golang(t *testing.T) {
	input := "golang"
	expectedResult := "gn0l2gaca"

	result := Encrypt(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
