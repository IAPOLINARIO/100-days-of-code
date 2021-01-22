package main

import (
	"reflect"
	"testing"
)

func Test_Eleet(t *testing.T) {
	nt := NewTranslator()

	expectedResult := "ELEET"

	result := nt.FromL33t("3L337")
	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
