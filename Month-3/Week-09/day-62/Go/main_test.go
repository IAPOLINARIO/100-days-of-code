package main

import (
	"reflect"
	"testing"
)

func Test_200_People(t *testing.T) {
	numberOfPeople := 200
	plants := 15
	expectedResult := 5

	result := harvest(numberOfPeople, plants)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_50000_People(t *testing.T) {
	numberOfPeople := 50000
	plants := 1
	expectedResult := 14

	result := harvest(numberOfPeople, plants)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_150000_People(t *testing.T) {
	numberOfPeople := 150000
	plants := 250
	expectedResult := 9

	result := harvest(numberOfPeople, plants)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
