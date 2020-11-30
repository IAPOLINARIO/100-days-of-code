package main

import (
	"reflect"
	"testing"
)

func Test_9_Turns(t *testing.T) {
	currentLock := "4089"
	targetLock := "5672"
	expectedResult := 9

	result := minTurns(currentLock, targetLock)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_2_Turns(t *testing.T) {
	currentLock := "1111"
	targetLock := "1100"
	expectedResult := 2

	result := minTurns(currentLock, targetLock)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_10_Turns(t *testing.T) {
	currentLock := "2391"
	targetLock := "4984"
	expectedResult := 10

	result := minTurns(currentLock, targetLock)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
