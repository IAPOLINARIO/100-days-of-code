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

func Test_Mom(t *testing.T) {
	nt := NewTranslator()

	expectedResult := "MOM"

	result := nt.FromL33t("(V)0(V)")
	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Wow(t *testing.T) {
	nt := NewTranslator()

	expectedResult := "WOW"

	result := nt.FromL33t("`//0`//")
	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Basic(t *testing.T) {
	nt := NewTranslator()

	expectedResult := "BASIC"

	result := nt.FromL33t("6451C")
	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
