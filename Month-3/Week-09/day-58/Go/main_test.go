package main

import (
	"reflect"
	"strings"
	"testing"
)

func Test_Game_1(t *testing.T) {
	input := []string{"3d6", "4d12", "1d10", "5d4"}
	expectedResult := "12: 5 4  316: 1 3 5  74:  49: 3 1 1 1  3"

	seed := int64(10) //time.Now().UnixNano()
	result := strings.ReplaceAll(strings.Join(rollTheDices(input, seed), ""), "\n", "")

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
