package main

import (
	"reflect"
	"testing"
)

func Test_Game_1(t *testing.T) {

	input := [][]string{
		{"X", "O", "O"},
		{"O", "X", "O"},
		{"O", "#", "X"}}

	expectedResult := "Player 1 wins"

	result := ticTacToe(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Game_2(t *testing.T) {

	input := [][]string{
		{"X", "O", "O"},
		{"O", "O", "O"},
		{"O", "#", "X"}}

	expectedResult := "Player 2 wins"

	result := ticTacToe(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Game_3(t *testing.T) {

	input := [][]string{
		{"X", "O", "O"},
		{"O", "#", "O"},
		{"O", "#", "X"}}

	expectedResult := "It's a Tie"

	result := ticTacToe(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
