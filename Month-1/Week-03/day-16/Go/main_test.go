package main

import (
	"reflect"
	"testing"
)

func Test_One_Stone(t *testing.T) {
	input := 1
	expectedResult := true

	result := canWin(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Four_Stones(t *testing.T) {
	input := 4
	expectedResult := false

	result := canWin(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Eight_Stones(t *testing.T) {
	input := 8
	expectedResult := false

	result := canWin(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Seven_Stones(t *testing.T) {
	input := 7
	expectedResult := true

	result := canWin(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Ten_Stones(t *testing.T) {
	input := 10
	expectedResult := true

	result := canWin(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_OneHundredAndTwentyTwo_Stones(t *testing.T) {
	input := 122
	expectedResult := true

	result := canWin(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_SevenHundresdAndFiftyNine_Stones(t *testing.T) {
	input := 759
	expectedResult := true

	result := canWin(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_OneThousandAndFiveHundred_Stones(t *testing.T) {
	input := 1500
	expectedResult := false

	result := canWin(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
