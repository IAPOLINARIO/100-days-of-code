package main

import "testing"

func TestFindNemo(t *testing.T) {
	tests := []struct {
		name string
		str  string
		want string
	}{
		{"Last", "I am finding Nemo !", "I found Nemo at 4!"},
		{"First", "Nemo is me", "I found Nemo at 1!"},
		{"Middle", "I Nemo am", "I found Nemo at 2!"},
		{"Not Found", "I Neo am", "I can't find Nemo :("},
		{"UTF-8", "This ✋ Nemo bye", "I found Nemo at 3!"},
		{"Spaces", "This   thing  Nemo bye", "I found Nemo at 3!"},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := FindNemo(tt.str)
			if got != tt.want {
				t.Fatalf("want: %s, got: %s", tt.want, got)
			}
		})
	}

}
