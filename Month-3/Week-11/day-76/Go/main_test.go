package main

import (
	"reflect"
	"testing"
)

func Test_Capacity_20(t *testing.T) {
	capacity := 20
	cakes := []Cake{{weight: 7, value: 160}, {weight: 3, value: 90}, {weight: 2, value: 15}}
	expectedResult := 555

	result := maxDuffelBagValue(cakes, capacity)
	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
