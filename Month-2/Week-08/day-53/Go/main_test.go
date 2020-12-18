package main

import (
	"fmt"
	"reflect"
	"testing"
)

func Test_Angle_Case_1(t *testing.T) {
	speed := 36.7
	angle := 45.

	Ymax, Xmax := javelinThrow(speed, angle)

	expectedResult := "Ymax=34m,Xmax=137m"

	result := fmt.Sprintf("%v,%v", Ymax, Xmax)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Angle_Case_2(t *testing.T) {
	speed := 51.3
	angle := 20.

	Ymax, Xmax := javelinThrow(speed, angle)

	expectedResult := "Ymax=15m,Xmax=172m"

	result := fmt.Sprintf("%v,%v", Ymax, Xmax)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Angle_Case_3(t *testing.T) {
	speed := 100.1
	angle := 89.

	Ymax, Xmax := javelinThrow(speed, angle)

	expectedResult := "Ymax=510m,Xmax=35m"

	result := fmt.Sprintf("%v,%v", Ymax, Xmax)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
