package main

import (
	"reflect"
	"testing"
)

func Test_Gravity_Case_1(t *testing.T) {
	input := [][]string{
		{"-", "#", "#", "-"},
		{"-", "-", "#", "-"},
		{"-", "-", "-", "#"},
		{"-", "-", "-", "-"}}

	expectedResult := [][]string{
		{"-", "-", "-", "-"},
		{"-", "-", "-", "-"},
		{"-", "-", "#", "-"},
		{"-", "#", "#", "#"}}

	result := *switchGravityOn(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Gravity_Case_2(t *testing.T) {
	input := [][]string{
		{"-", "#", "#", "-"},
		{"-", "-", "-", "-"},
		{"-", "-", "-", "-"},
		{"-", "-", "-", "-"}}

	expectedResult := [][]string{
		{"-", "-", "-", "-"},
		{"-", "-", "-", "-"},
		{"-", "-", "-", "-"},
		{"-", "#", "#", "-"}}

	result := *switchGravityOn(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Gravity_Case_3(t *testing.T) {
	input := [][]string{
		{"-", "#", "#", "#", "#", "-"},
		{"#", "-", "-", "#", "#", "-"},
		{"-", "#", "-", "-", "-", "-"},
		{"-", "-", "-", "-", "-", "-"}}

	expectedResult := [][]string{
		{"-", "-", "-", "-", "-", "-"},
		{"-", "-", "-", "-", "-", "-"},
		{"-", "#", "-", "#", "#", "-"},
		{"#", "#", "#", "#", "#", "-"}}

	result := *switchGravityOn(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
