package main

import (
	"testing"
)

func TestFindNemoAtPosition1(t *testing.T) {
	testInput := "Nemo is me"
	expectedResult := 1
	nemoIndex := findNemo(testInput)

	if nemoIndex != expectedResult {
		t.Errorf("Finding Nemo position was incorrect, got: %d, want: %d.", nemoIndex, expectedResult)
	}
}

func TestFindNemoAtPosition2(t *testing.T) {
	testInput := "I'm Nemo"
	expectedResult := 2
	nemoIndex := findNemo(testInput)

	if nemoIndex != expectedResult {
		t.Errorf("Finding Nemo position was incorrect, got: %d, want: %d.", nemoIndex, expectedResult)
	}
}

func TestFindNemoAtPosition4(t *testing.T) {
	testInput := "Ok, you found Nemo"
	expectedResult := 4
	nemoIndex := findNemo(testInput)

	if nemoIndex != expectedResult {
		t.Errorf("Finding Nemo position was incorrect, got: %d, want: %d.", nemoIndex, expectedResult)
	}
}

func TestFindNemoAtPosition5(t *testing.T) {
	testInput := "Right, now you found Nemo"
	expectedResult := 5
	nemoIndex := findNemo(testInput)

	if nemoIndex != expectedResult {
		t.Errorf("Finding Nemo position was incorrect, got: %d, want: %d.", nemoIndex, expectedResult)
	}
}
