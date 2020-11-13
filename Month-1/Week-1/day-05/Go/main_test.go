package main

import (
	"testing"
)

func TestOnePairSocks(t *testing.T) {
	testInput := "ADECBAFGT"
	expectedResult := 1

	result, _ := sockPairs(testInput)

	if result != expectedResult {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func TestTwoPairSocks(t *testing.T) {
	testInput := "AABCB"
	expectedResult := 2

	result, _ := sockPairs(testInput)

	if result != expectedResult {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func TestZeroPairSocks(t *testing.T) {
	testInput := "ABCDEFG"
	expectedResult := 0

	result, _ := sockPairs(testInput)

	if result != expectedResult {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func TestFivePairSocks(t *testing.T) {
	testInput := "ABCDEQWEREDCBANM"
	expectedResult := 5

	result, _ := sockPairs(testInput)

	if result != expectedResult {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func TestSixPairSocks(t *testing.T) {
	testInput := "ABCDEQWEREDCBANPMP"
	expectedResult := 6

	result, _ := sockPairs(testInput)

	if result != expectedResult {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
