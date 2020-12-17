package main

import (
	"reflect"
	"testing"
)

func Test_2_Servings_Per_Philosopher(t *testing.T) {
	names := []string{"Ismael", "Canova", "Joao", "Dito", "Monan", "Clemente", "Gian", "Evandro"}
	dineEachePhilosopher := 2
	expectedResult := 2
	_, servings := startTheDiner(names, dineEachePhilosopher)

	if !reflect.DeepEqual(servings, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", servings, expectedResult)
	}
}

func Test_5_Servings_Per_Philosopher(t *testing.T) {
	names := []string{"Ismael", "Canova", "Joao", "Dito", "Monan", "Clemente", "Gian", "Evandro"}
	dineEachePhilosopher := 5
	expectedResult := 5
	_, servings := startTheDiner(names, dineEachePhilosopher)

	if !reflect.DeepEqual(servings, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", servings, expectedResult)
	}
}

func Test_10_Servings_Per_Philosopher(t *testing.T) {
	names := []string{"Ismael", "Canova", "Joao", "Dito", "Monan", "Clemente", "Gian", "Evandro"}
	dineEachePhilosopher := 10
	expectedResult := 10
	_, servings := startTheDiner(names, dineEachePhilosopher)

	if !reflect.DeepEqual(servings, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", servings, expectedResult)
	}
}
