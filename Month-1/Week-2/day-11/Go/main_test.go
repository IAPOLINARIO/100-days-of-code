package main

import (
	"reflect"
	"strings"
	"testing"
)

func Test_Ip_2(t *testing.T) {
	input := "25525511135"
	expectedResult := "255.255.11.135,255.255.111.35"

	result := strings.Join(restoreIpAddresses(input), ",")

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Ip_0(t *testing.T) {
	input := "0000"
	expectedResult := "0.0.0.0"

	result := strings.Join(restoreIpAddresses(input), ",")

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Ip_1(t *testing.T) {
	input := "1111"
	expectedResult := "1.1.1.1"

	result := strings.Join(restoreIpAddresses(input), ",")

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Ip_3(t *testing.T) {
	input := "010010"
	expectedResult := "0.10.0.10,0.100.1.0"

	result := strings.Join(restoreIpAddresses(input), ",")

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Ip_4(t *testing.T) {
	input := "101023"
	expectedResult := "1.0.10.23,1.0.102.3,10.1.0.23,10.10.2.3,101.0.2.3"

	result := strings.Join(restoreIpAddresses(input), ",")

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
