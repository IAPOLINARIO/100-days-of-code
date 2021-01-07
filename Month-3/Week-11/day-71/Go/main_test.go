package main

import (
	"reflect"
	"testing"
)

func Test_Lights_1(t *testing.T) {
	input := [][]int{{2, 4}, {3, 6}, {1, 3}, {6, 8}}

	expectedResult := 7

	result := lightsOn(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Lights_2(t *testing.T) {
	input := [][]int{{6, 8}, {5, 8}, {8, 9}, {5, 7}, {4, 7}}

	expectedResult := 5

	result := lightsOn(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Lights_3(t *testing.T) {
	input := [][]int{{1, 3}, {2, 3}, {4, 5}}

	expectedResult := 3

	result := lightsOn(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
