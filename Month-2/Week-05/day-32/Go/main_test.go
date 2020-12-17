package main

import (
	"reflect"
	"testing"
)

func Test_431(t *testing.T) {
	input_board := []int{100, 90, 90, 80}
	input_played := []int{70, 80, 105}
	expectedResult := []int{4, 3, 1}

	result := playerRank(input_board, input_played)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_113(t *testing.T) {
	input_board := []int{100, 90, 90, 80}
	input_played := []int{106, 107, 105}
	expectedResult := []int{1, 1, 1}

	result := playerRank(input_board, input_played)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_65421(t *testing.T) {
	input_board := []int{100, 90, 90, 80, 75, 60}
	input_played := []int{50, 65, 77, 90, 102}
	expectedResult := []int{6, 5, 4, 2, 1}

	result := playerRank(input_board, input_played)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_6421(t *testing.T) {
	input_board := []int{100, 100, 50, 40, 40, 20, 10}
	input_played := []int{5, 25, 50, 120}
	expectedResult := []int{6, 4, 2, 1}

	result := playerRank(input_board, input_played)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
