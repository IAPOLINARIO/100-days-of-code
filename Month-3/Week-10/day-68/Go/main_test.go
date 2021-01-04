package main

import (
	"reflect"
	"strings"
	"testing"
)

func Test_IP_1(t *testing.T) {
	input := "123654789"

	expectedResult := "8.00cm"

	result := CalculateTypeDistance(strings.Split(input, ""))

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_IP_2(t *testing.T) {
	input := "127.0.0.1"

	expectedResult := "7.81cm"

	result := CalculateTypeDistance(strings.Split(input, ""))

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_IP_3(t *testing.T) {
	input := "192.168.0.10"

	expectedResult := "22.20cm"

	result := CalculateTypeDistance(strings.Split(input, ""))

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_IP_4(t *testing.T) {
	input := "1111"

	expectedResult := "0.00cm"

	result := CalculateTypeDistance(strings.Split(input, ""))

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
