package main

import (
	"reflect"
	"testing"
)

func Test_Grid_One(t *testing.T) {
	n := 5
	r := 2
	c := 3

	grid := [][]string{
		{"-", "-", "-", "-", "-"},
		{"-", "-", "-", "-", "-"},
		{"p", "-", "-", "m", "-"},
		{"-", "-", "-", "-", "-"},
		{"-", "-", "-", "-", "-"}}

	result := findPrincess(n, r, c, grid)
	expectedResult := "LEFT LEFT LEFT "

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Grid_Two(t *testing.T) {
	n := 4
	r := 2
	c := 3

	grid := [][]string{
		{"-", "-", "-", "-"},
		{"p", "-", "-", "-"},
		{"-", "-", "-", "m"},
		{"-", "-", "-", "-"}}

	result := findPrincess(n, r, c, grid)
	expectedResult := "LEFT LEFT LEFT "

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
