package main

import (
	"reflect"
	"testing"
)

func Test_I_AM_FINE_TODAY(t *testing.T) {
	input := "O S, GOMR YPFSU/"
	expectedResult := "I AM FINE TODAY."

	result := keyboardMistakeFix(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_PAU_NO_SEU_CU(t *testing.T) {
	input := "[SI MP DRI VI"
	expectedResult := "PAU NO SEU CU"

	result := keyboardMistakeFix(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_BOLSOMINION_TUDO_GADO(t *testing.T) {
	input := "NP;DP,OMOPM YIFP HSFP"
	expectedResult := "BOLSOMINION TUDO GADO"

	result := keyboardMistakeFix(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
func Test_LACRE_13_NAS_ELEICOES_DE_2022(t *testing.T) {
	input := ";SVTR 24 MSD R;ROVPRD FR 3-33"
	expectedResult := "LACRE 13 NAS ELEICOES DE 2022"

	result := keyboardMistakeFix(input)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
