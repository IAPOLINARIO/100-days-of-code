package main

import (
	"reflect"
	"testing"
)

func Test_58(t *testing.T) {
	keyboards := []int{40, 50, 60}
	drives := []int{5, 8, 12}
	budget := 60
	expectedResult := 58

	result := getMoneySpent(keyboards, drives, budget)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_60(t *testing.T) {
	keyboards := []int{40, 50, 60}
	drives := []int{5, 8, 12, 10}
	budget := 60
	expectedResult := 60

	result := getMoneySpent(keyboards, drives, budget)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_100(t *testing.T) {
	keyboards := []int{40, 50, 60, 80}
	drives := []int{5, 8, 12, 10, 20}
	budget := 105
	expectedResult := 100

	result := getMoneySpent(keyboards, drives, budget)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_200(t *testing.T) {
	keyboards := []int{10, 50, 101, 99}
	drives := []int{50, 100, 20, 30, 40}
	budget := 200
	expectedResult := 199

	result := getMoneySpent(keyboards, drives, budget)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
