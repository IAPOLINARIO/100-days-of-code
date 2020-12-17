package main

import (
	"reflect"
	"testing"
)

func Test_8(t *testing.T) {
	input := []byte("AAABBB")
	expectedResult := 8

	result := leastInterval(input, 2)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_16(t *testing.T) {
	input := []byte("AAAAAABCDEFG")
	expectedResult := 16

	result := leastInterval(input, 2)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
