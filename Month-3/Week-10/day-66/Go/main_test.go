package main

import (
	"fmt"
	"reflect"
	"testing"
)

func Test_ISBN(t *testing.T) {
	input := generateISBN()

	fmt.Printf("ISBN: %v\n", input)
	expectedResult := true

	result := validateISBN(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
