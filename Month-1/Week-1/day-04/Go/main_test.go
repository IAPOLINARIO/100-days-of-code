package main

import "testing"

func TestProgressDays_2(t *testing.T) {
	testInput := "[3, 4, 1, 2]"
	expectedResult := 2

	result, _ := ProgressDays(testInput)

	if result != expectedResult {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func TestProgressDays_4(t *testing.T) {
	testInput := "[3, 4, 1, 2, 4, 7]"
	expectedResult := 4

	result, _ := ProgressDays(testInput)

	if result != expectedResult {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
func TestProgressDays_6(t *testing.T) {
	testInput := "[1, 2, 3, 4, 5, 6, 7]"
	expectedResult := 6

	result, _ := ProgressDays(testInput)

	if result != expectedResult {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func TestProgressDays_7(t *testing.T) {
	testInput := "[1, 2, 3, 4, 5, 6, 7, 10]"
	expectedResult := 7

	result, _ := ProgressDays(testInput)

	if result != expectedResult {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func TestProgressDays_0(t *testing.T) {
	testInput := "[5, 5, 3, 2]"
	expectedResult := 0

	result, _ := ProgressDays(testInput)

	if result != expectedResult {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
