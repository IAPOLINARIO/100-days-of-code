package main

import (
	"reflect"
	"testing"
)

func Test_Triangle_17(t *testing.T) {
	side1 := 10
	side2 := 8
	expectedResult := 17

	result := nextEdge(side1, side2)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Triangle_11(t *testing.T) {
	side1 := 5
	side2 := 7
	expectedResult := 11

	result := nextEdge(side1, side2)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Triangle_10(t *testing.T) {
	side1 := 9
	side2 := 2
	expectedResult := 10

	result := nextEdge(side1, side2)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
