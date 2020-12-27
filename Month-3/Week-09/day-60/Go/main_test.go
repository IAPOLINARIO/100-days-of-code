package main

import (
	"reflect"
	"strings"
	"testing"
)

func Test_Game_100(t *testing.T) {
	input := 100
	var sb strings.Builder
	sb.WriteString("100 -1\n")
	sb.WriteString("33 0\n")
	sb.WriteString("11 1\n")
	sb.WriteString("4 -1\n")
	sb.WriteString("1")

	expectedResult := sb.String()

	result := playTheGame(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Game_200(t *testing.T) {
	input := 200
	var sb strings.Builder
	sb.WriteString("200 1\n")
	sb.WriteString("67 -1\n")
	sb.WriteString("22 -1\n")
	sb.WriteString("7 -1\n")
	sb.WriteString("2 1\n")
	sb.WriteString("1")

	expectedResult := sb.String()

	result := playTheGame(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Game_5000(t *testing.T) {
	input := 5000
	var sb strings.Builder
	sb.WriteString("5000 1\n")
	sb.WriteString("1667 1\n")
	sb.WriteString("556 -1\n")
	sb.WriteString("185 1\n")
	sb.WriteString("62 1\n")
	sb.WriteString("21 0\n")
	sb.WriteString("7 -1\n")
	sb.WriteString("2 1\n")
	sb.WriteString("1")

	expectedResult := sb.String()

	result := playTheGame(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
