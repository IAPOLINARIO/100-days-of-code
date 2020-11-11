package main

import (
	"reflect"
	"testing"
)

func Test_Bing_URL(t *testing.T) {
	input := "https://bing.com/search"
	customURL := "isma.me"
	expectedResult := "https://isma.me/arnhigec"

	result, _ := ShortMyUrl(input, customURL)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Pegadinha_Malandro_URL(t *testing.T) {
	input := "https://miro.medium.com/max/600/0*XnbOuNxzwr3F_ZRV.jpg"
	customURL := "ra.ieie"
	expectedResult := "https://ra.ieie/dgaooxOw"

	result, _ := ShortMyUrl(input, customURL)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Gado_Demais_URL(t *testing.T) {
	input := "https://cdn.dicionariopopular.com/imagens/gado-demais-cke.jpg"
	customURL := "gado.demais"
	expectedResult := "https://gado.demais/algog/m-"

	result, _ := ShortMyUrl(input, customURL)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_PT_URL(t *testing.T) {
	input := "https://pt.org.br/filiacao"
	customURL := "lula.lindo"
	expectedResult := "https://lula.lindo/gciii.br"

	result, _ := ShortMyUrl(input, customURL)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Bolsonaro_Mente_URL(t *testing.T) {
	input := "https://www1.folha.uol.com.br/colunas/bruno-boghossian/2020/11/bolsonaro-mente-e-usa-tumulo-como-palanque-para-buscar-vitoria-particular.shtml"
	customURL := "bozo.ladrao"
	expectedResult := "https://bozo.ladrao/uopbb-nc"

	result, _ := ShortMyUrl(input, customURL)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
