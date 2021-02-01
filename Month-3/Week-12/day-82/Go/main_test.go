package main

import (
	"reflect"
	"strings"
	"testing"
)

func Test_Scenario_1(t *testing.T) {
	input := []int64{4, 132, 1000, 7, 111111111111111110}

	expectedResult := "Case #1: 129,Case #2: 999,Case #3: 7,Case #4: 99999999999999999"

	result := strings.Join(CheckTidyNumber(input), ",")
	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
