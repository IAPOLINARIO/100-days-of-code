package main

import (
	"reflect"
	"testing"
)

func Test_Color_1(t *testing.T) {
	rgbObj := NewRGB(0, 128, 192)
	expectedResult := "#0080c0"

	result := rgbObj.rgb2hex()

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Color_2(t *testing.T) {
	rgbObj := NewRGB(45, 255, 192)
	expectedResult := "#2dffc0"

	result := rgbObj.rgb2hex()

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Color_3(t *testing.T) {
	rgbObj := NewRGB(0, 0, 0)
	expectedResult := "#000000"

	result := rgbObj.rgb2hex()

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
