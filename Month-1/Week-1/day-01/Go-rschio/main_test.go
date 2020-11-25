package main

import "testing"

func TestCalcAge(t *testing.T) {
	tests := []struct {
		name string
		age  int
		want int
	}{
		{"first", 65, 23725},
		{"zero", 0, 0},
		{"twenty", 20, 7300},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := CalcAge(tt.age)
			if got != tt.want {
				t.Fatalf("want: %d, got: %d", tt.want, got)
			}
		})
	}
}
