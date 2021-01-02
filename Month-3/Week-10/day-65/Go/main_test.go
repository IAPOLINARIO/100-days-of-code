package main

import (
	"reflect"
	"testing"
)

func Test_ISBN_1(t *testing.T) {
	input := "0-7475-3269-9"
	expectedResult := true

	result := validateISBN(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_ISBN_2(t *testing.T) {
	input := "1-56881111-X"
	expectedResult := true

	result := validateISBN(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_ISBN_3(t *testing.T) {
	input := "1-56881118-X"
	expectedResult := false

	result := validateISBN(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_ISBN_4(t *testing.T) {
	input := "0-684-84328-5"
	expectedResult := true

	result := validateISBN(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_ISBN_5(t *testing.T) {
	input := "1-684-84328-5"
	expectedResult := false

	result := validateISBN(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_ISBN_6(t *testing.T) {
	input := "0-9752298-0-X"
	expectedResult := true

	result := validateISBN(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
