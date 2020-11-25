package main

import (
	"reflect"
	"testing"
)

func Test_41_3_SurvivorL(t *testing.T) {
	input_soldiers := 41
	kill_interval := 3
	expectedResult := 31

	result := finalSurvivor(input_soldiers, kill_interval)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_35_11_SurvivorL(t *testing.T) {
	input_soldiers := 35
	kill_interval := 11
	expectedResult := 18

	result := finalSurvivor(input_soldiers, kill_interval)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_11_1_SurvivorL(t *testing.T) {
	input_soldiers := 11
	kill_interval := 1
	expectedResult := 11

	result := finalSurvivor(input_soldiers, kill_interval)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_2_2_SurvivorL(t *testing.T) {
	input_soldiers := 2
	kill_interval := 2
	expectedResult := 1

	result := finalSurvivor(input_soldiers, kill_interval)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
