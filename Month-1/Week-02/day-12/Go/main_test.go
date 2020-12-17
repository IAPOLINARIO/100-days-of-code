package main

import (
	"reflect"
	"strings"
	"testing"
)

func Test_Mountain_1(t *testing.T) {
	input := "1,3,5,4,3,2"
	expectedResult := "mountain"

	arrayInput := strings.Split(input, ",")

	result := LandscapeType(arrayInput)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Mountain_2(t *testing.T) {
	input := "-1,0,-1"
	expectedResult := "mountain"

	arrayInput := strings.Split(input, ",")

	result := LandscapeType(arrayInput)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Mountain_3(t *testing.T) {
	input := "-1,-1,0,-1,-1"
	expectedResult := "mountain"

	arrayInput := strings.Split(input, ",")

	result := LandscapeType(arrayInput)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Valley_1(t *testing.T) {
	input := "10,9,8,7,2,3,4,5"
	expectedResult := "valley"

	arrayInput := strings.Split(input, ",")

	result := LandscapeType(arrayInput)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Valley_3(t *testing.T) {
	input := "9,8,9"
	expectedResult := "valley"

	arrayInput := strings.Split(input, ",")

	result := LandscapeType(arrayInput)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Invalid_1(t *testing.T) {
	input := "1,2,3,2,4,1"
	expectedResult := "neither"

	arrayInput := strings.Split(input, ",")

	result := LandscapeType(arrayInput)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Invalid_2(t *testing.T) {
	input := "5,4,3,2,1"
	expectedResult := "neither"

	arrayInput := strings.Split(input, ",")

	result := LandscapeType(arrayInput)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
