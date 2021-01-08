package main

import (
	"reflect"
	"testing"
)

func Test_Eleet(t *testing.T) {
	nt := NewTranslator()

	expectedResult := "3L337"

	result := nt.ToL33t("ELEET")
	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Mom(t *testing.T) {
	nt := NewTranslator()

	expectedResult := "(V)0(V)"

	result := nt.ToL33t("MOM")
	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Wow(t *testing.T) {
	nt := NewTranslator()

	expectedResult := "`//0`//"

	result := nt.ToL33t("WOW")
	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Basic(t *testing.T) {
	nt := NewTranslator()

	expectedResult := "6451C"

	result := nt.ToL33t("BASIC")
	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
