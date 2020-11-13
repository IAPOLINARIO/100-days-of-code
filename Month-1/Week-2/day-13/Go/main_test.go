package main

import (
	"reflect"
	"testing"
)

func Test1Bags_Fit(t *testing.T) {
	input := []int{5, 5}
	expectedResult := true
	numberofBags := 1

	result := CanFit(input, numberofBags)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test1Bags_DoesNotFit(t *testing.T) {
	input := []int{5, 6}
	expectedResult := false
	numberofBags := 1

	result := CanFit(input, numberofBags)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test4Bags_Fit(t *testing.T) {
	input := []int{2, 1, 2, 5, 4, 3, 6, 1, 1, 9, 3, 2}
	expectedResult := true
	numberofBags := 4

	result := CanFit(input, numberofBags)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test4Bags_DoesNotFit(t *testing.T) {
	input := []int{2, 7, 1, 3, 3, 4, 7, 4, 1, 8, 2}
	expectedResult := false
	numberofBags := 4

	result := CanFit(input, numberofBags)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test5Bags_Fit(t *testing.T) {
	input := []int{2, 7, 1, 3, 3, 4, 7, 4, 1, 8, 2}
	expectedResult := true
	numberofBags := 5

	result := CanFit(input, numberofBags)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test5Bags_DoesNotFit(t *testing.T) {
	input := []int{8, 7, 1, 6, 3, 4, 7, 4, 8, 8, 7}
	expectedResult := false
	numberofBags := 5

	result := CanFit(input, numberofBags)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test6Bags_Fit(t *testing.T) {
	input := []int{4, 7, 1, 6, 3, 4, 7, 4, 8, 8, 7}
	expectedResult := true
	numberofBags := 6

	result := CanFit(input, numberofBags)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Gian_Fit(t *testing.T) {
	input := []int{4, 7, 1, 6, 3, 4, 7, 4, 8, 8, 7}
	expectedResult := true
	numberofBags := 6

	result := CanFit(input, numberofBags)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
