package main

import (
	"reflect"
	"testing"
)

func Test_Balanced_1(t *testing.T) {
	input := "xxxyyyzzz"
	expectedResult := true

	result := balanced_bonus(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Balanced_2(t *testing.T) {
	input := "abccbaabccba"
	expectedResult := true

	result := balanced_bonus(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Balanced_3(t *testing.T) {
	input := "xxxyyyzzzz"
	expectedResult := false

	result := balanced_bonus(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
func Test_Balanced_4(t *testing.T) {
	input := "abcdefghijklmnopqrstuvwxyz"
	expectedResult := true

	result := balanced_bonus(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Balanced_5(t *testing.T) {
	input := "pqq"
	expectedResult := false

	result := balanced_bonus(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Balanced_6(t *testing.T) {
	input := "fdedfdeffeddefeeeefddf"
	expectedResult := false

	result := balanced_bonus(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Balanced_7(t *testing.T) {
	input := "www"
	expectedResult := true

	result := balanced_bonus(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Balanced_8(t *testing.T) {
	input := "x"
	expectedResult := true

	result := balanced_bonus(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Balanced_9(t *testing.T) {
	input := ""
	expectedResult := true

	result := balanced_bonus(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
