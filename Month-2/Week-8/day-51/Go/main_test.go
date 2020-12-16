package main

import (
	"reflect"
	"testing"
)

func Test_Asteroid_1(t *testing.T) {
	input := []int{5, 10, -5}
	exploded := checkExplodedAsteroids(input)
	expectedResult := []int{5, 10}

	result := getBiggestAsteroid(input, exploded)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Asteroid_2(t *testing.T) {
	input := []int{-8, 8}
	exploded := checkExplodedAsteroids(input)
	expectedResult := len([]int{})

	result := len(getBiggestAsteroid(input, exploded))

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Asteroid_3(t *testing.T) {
	input := []int{-2, -1, 1, 2}
	exploded := checkExplodedAsteroids(input)
	expectedResult := []int{-2, -1, 1, 2}

	result := getBiggestAsteroid(input, exploded)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
