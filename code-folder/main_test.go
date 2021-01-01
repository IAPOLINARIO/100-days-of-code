package main

import (
	"bytes"
	"log"
	"os"
	"testing"
)

func captureOutput(f func()) string {
	var buf bytes.Buffer
	log.SetOutput(&buf)
	f()
	log.SetOutput(os.Stderr)
	return buf.String()
}

func TestMain(t *testing.T) {
	main()
}

func TestVals(t *testing.T) {
	t.Run("Testando funcao com retornos multiplos", func(t *testing.T) {
		v1, v2 := vals()
		if v1 != 3 || v2 != 7 {
			t.Errorf("valor errado")
		}
	})
}

func TestSum(t *testing.T) {
	t.Run("Testando soma: 1 + 1 = 2", func(t *testing.T) {

		if sum(1, 1) != 2 {
			t.Errorf("valor errado")
		}
	})
	t.Run("Testando soma: 3 + 5 = 8", func(t *testing.T) {

		if sum(3, 5) != 8 {
			t.Errorf("valor errado")
		}
	})
	t.Run("Testando soma: 7 + 11 = 18", func(t *testing.T) {

		if sum(7, 11) != 18 {
			t.Errorf("valor errado")
		}
	})
}
