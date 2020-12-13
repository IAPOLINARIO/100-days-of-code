package main

import (
	"reflect"
	"strings"
	"testing"
)

func Test_Tree_5(t *testing.T) {
	input := 5
	expectedResult := 25

	result := strings.Count(buildChristmasTree(input), treeBuildingBlock)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Tree_10(t *testing.T) {
	input := 10
	expectedResult := 100

	result := strings.Count(buildChristmasTree(input), treeBuildingBlock)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Tree_50(t *testing.T) {
	input := 50
	expectedResult := 2500

	result := strings.Count(buildChristmasTree(input), treeBuildingBlock)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Tree_500(t *testing.T) {
	input := 500
	expectedResult := 250000

	result := strings.Count(buildChristmasTree(input), treeBuildingBlock)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
