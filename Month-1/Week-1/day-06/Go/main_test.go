package main

import (
	"testing"
)

func Test_1_Prime(t *testing.T) {
	testInput := 1
	expectedResult := 2

	result, _ := NextPrime(testInput)

	if result != expectedResult {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_2_Prime(t *testing.T) {
	testInput := 2
	expectedResult := 2

	result, _ := NextPrime(testInput)

	if result != expectedResult {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_5_Prime(t *testing.T) {
	testInput := 5
	expectedResult := 5

	result, _ := NextPrime(testInput)

	if result != expectedResult {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_480_Prime(t *testing.T) {
	testInput := 480
	expectedResult := 487

	result, _ := NextPrime(testInput)

	if result != expectedResult {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_788_Prime(t *testing.T) {
	testInput := 788
	expectedResult := 797

	result, _ := NextPrime(testInput)

	if result != expectedResult {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_984_Prime(t *testing.T) {
	testInput := 984
	expectedResult := 991

	result, _ := NextPrime(testInput)

	if result != expectedResult {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_997_Prime(t *testing.T) {
	testInput := 997
	expectedResult := 997

	result, _ := NextPrime(testInput)

	if result != expectedResult {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_5005_Prime(t *testing.T) {
	testInput := 5005
	expectedResult := 5009

	result, _ := NextPrime(testInput)

	if result != expectedResult {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_999999999_Prime(t *testing.T) {
	testInput := 999999999
	expectedResult := 1000000007

	result, _ := NextPrime(testInput)

	if result != expectedResult {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
