package main

import (
	"testing"
)

func TestAllVeganSkewer(t *testing.T) {
	testInput := ` ["--oooo-ooo--","--oo--o--oo--","--oo--o--oo--"] `
	expectedResult := "[3,0]"

	result, _ := parseJson(testInput)

	if result != expectedResult {
		t.Errorf("Your evaluation was incorrect, got: %s, want: %s", result, expectedResult)
	}
}

func TestAllMeatSkewer(t *testing.T) {
	testInput := ` ["--xxxx-xxx--","--x--oo--xxx--","--xox--x--xxx--", "-x-x--xx--x--oxx--"] `
	expectedResult := "[0,4]"

	result, _ := parseJson(testInput)

	if result != expectedResult {
		t.Errorf("Your skewer evaluation was incorrect, got: %s, want: %s", result, expectedResult)
	}
}

func Test3VeganAnd2Meat(t *testing.T) {
	testInput := ` ["--oo--o--oo--x-xxx-x-","--oooo-ooo--","--oo--o--oo--","--oo--x--x--","--oo--o--oo--"] `
	expectedResult := "[3,2]"

	result, _ := parseJson(testInput)

	if result != expectedResult {
		t.Errorf("Your skewer evaluation was incorrect, got: %s, want: %s", result, expectedResult)
	}
}

func Test3VeganAnd3Meat(t *testing.T) {
	testInput := ` ["--oo--o--oo--x-xxx-x-","--oooo-ooo--","--oo--o--oo--","--oo--x--x--","--oo--o--oo--", "--oo--o--xo--"] `
	expectedResult := "[3,3]"

	result, _ := parseJson(testInput)

	if result != expectedResult {
		t.Errorf("Your skewer evaluation was incorrect, got: %s, want: %s", result, expectedResult)
	}
}
