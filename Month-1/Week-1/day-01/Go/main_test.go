package main

import "testing"

func Test65AgeConvertion(t *testing.T) {
	age, err := CalculateAge("65")
	expectedAge := int64(23725)

	if err != nil || age != expectedAge {
		t.Errorf("Age calculation was incorrect, got: %d, want: %d.", age, expectedAge)
	}
}

func Test20AgeConvertion(t *testing.T) {
	age, err := CalculateAge("20")
	expectedAge := int64(7300)

	if err != nil || age != expectedAge {
		t.Errorf("Age calculation was incorrect, got: %d, want: %d.", age, expectedAge)
	}
}

func Test40AgeConvertion(t *testing.T) {
	age, err := CalculateAge("40")
	expectedAge := int64(14600)

	if err != nil || age != expectedAge {
		t.Errorf("Age calculation was incorrect, got: %d, want: %d.", age, expectedAge)
	}
}

func TestStringAgeConvertion(t *testing.T) {
	_, err := CalculateAge("xpto")

	if err == nil {
		t.Errorf("Age calculation was incorrect, should have thrown an exception")
	}
}
