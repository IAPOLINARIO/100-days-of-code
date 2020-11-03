package main

import (
	"strings"
	"testing"
)

func TestRainTrap6(t *testing.T) {
	inputValue := "[0,1,0,2,1,0,1,3,2,1,2,1]"
	waterMap := strings.Split(strings.ReplaceAll(strings.ReplaceAll(inputValue, "[", ""), "]", ""), ",")
	expectedResult := 6

	result := buildElevationMap(waterMap)

	if result != expectedResult {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func TestRainTrap2(t *testing.T) {
	inputValue := "[1,0,1,0,1]"
	waterMap := strings.Split(strings.ReplaceAll(strings.ReplaceAll(inputValue, "[", ""), "]", ""), ",")
	expectedResult := 2

	result := buildElevationMap(waterMap)

	if result != expectedResult {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func TestRainTrap7(t *testing.T) {
	inputValue := "[0,1,0,2,1,0,1,3,2,1,2,1,2]"
	waterMap := strings.Split(strings.ReplaceAll(strings.ReplaceAll(inputValue, "[", ""), "]", ""), ",")
	expectedResult := 7

	result := buildElevationMap(waterMap)

	if result != expectedResult {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func TestRainTrap9(t *testing.T) {
	inputValue := "[4,2,0,3,2,5]"
	waterMap := strings.Split(strings.ReplaceAll(strings.ReplaceAll(inputValue, "[", ""), "]", ""), ",")
	expectedResult := 9

	result := buildElevationMap(waterMap)

	if result != expectedResult {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
