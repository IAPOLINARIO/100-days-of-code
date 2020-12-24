package main

import (
	"reflect"
	"strings"
	"testing"
)

func Test_Word_1(t *testing.T) {
	input := "hello world"
	expectedResult := "68 65 6c 6c 6f 20 77 6f 72 6c 64"

	result := strings.Join(toHex(input), " ")

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Word_2(t *testing.T) {
	input := "Big Boi"
	expectedResult := "42 69 67 20 42 6f 69"

	result := strings.Join(toHex(input), " ")

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Word_3(t *testing.T) {
	input := "Marty Poppinson"
	expectedResult := "4d 61 72 74 79 20 50 6f 70 70 69 6e 73 6f 6e"

	result := strings.Join(toHex(input), " ")

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Word_4(t *testing.T) {
	input := "Bolsominion eh tudo gado"
	expectedResult := "42 6f 6c 73 6f 6d 69 6e 69 6f 6e 20 65 68 20 74 75 64 6f 20 67 61 64 6f"

	result := strings.Join(toHex(input), " ")

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
