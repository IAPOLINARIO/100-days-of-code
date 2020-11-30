package main

import (
	"reflect"
	"testing"
)

func Test_3_Kids(t *testing.T) {
	kids := 3
	coins := []int{1, 2, 3, 2, 2, 2, 3}
	expectedResult := true

	result := coinsDiv(kids, coins)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_4_Kids(t *testing.T) {
	kids := 4
	coins := []int{1, 2, 3, 2, 2, 2, 3}
	expectedResult := false

	result := coinsDiv(kids, coins)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_5_Kids(t *testing.T) {
	kids := 5
	coins := []int{2, 2, 1, 1, 2, 2, 3, 1, 2, 1, 2, 1}
	expectedResult := true

	result := coinsDiv(kids, coins)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_10_Kids(t *testing.T) {
	kids := 10
	coins := []int{2, 3, 3, 2, 5, 2, 3, 2, 3, 5, 2, 3, 2, 3, 2, 3, 5, 5, 5, 5}
	expectedResult := false

	result := coinsDiv(kids, coins)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
