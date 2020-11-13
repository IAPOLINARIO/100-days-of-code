package main

import (
	"reflect"
	"testing"
)

func Test_London(t *testing.T) {
	input := "London"
	latitude := 0.0
	longitude := 0.0
	expectedResult := 5

	result := len(readGoogleAPI(input, latitude, longitude))

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Sao_Paulo(t *testing.T) {
	input := "Sao Paulo"
	latitude := -23.5505199
	longitude := -46.63330939999999
	expectedResult := 5

	result := len(readGoogleAPI(input, latitude, longitude))

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Amsterdam(t *testing.T) {
	input := "Amsterdam"
	latitude := 52.3675734
	longitude := 4.9041389
	expectedResult := 5

	result := len(readGoogleAPI(input, latitude, longitude))

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
func Test_None(t *testing.T) {
	input := "54as5d asd asd"
	latitude := 0.0
	longitude := 0.0
	expectedResult := 0

	result := len(readGoogleAPI(input, latitude, longitude))

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
