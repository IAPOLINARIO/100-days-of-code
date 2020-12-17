package main

import (
	"reflect"
	"testing"
)

func Test_Bad_File(t *testing.T) {
	filePath := "..\\..\\..\\..\\assets\\day-35_sample_3_invalid.txt"
	expectedResult := "BAD FILE!"

	result := parseFile(filePath)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Valid_File(t *testing.T) {
	filePath := "..\\..\\..\\..\\assets\\day-35_sample_1_valid.txt"
	expectedResult := "[The gopher cannot escape., The gopher can escape through the hole at (2.500,2.500).]"

	result := parseFile(filePath)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
