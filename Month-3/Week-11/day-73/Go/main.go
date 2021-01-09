package main

import (
	"fmt"
	"strings"
)

type NetTranslator struct {
	originalWord   string
	translatedWord string
}

func NewTranslator() *NetTranslator {
	return new(NetTranslator)
}

func (nt *NetTranslator) FromL33t(originalWord string) string {

	nt.originalWord = originalWord
	nt.translatedWord = ""
	dict := nt.GetDictionary()

	for i := 0; i < len(originalWord); i++ {
		currentChar := string(originalWord[i])

		if strings.ContainsAny(currentChar, "(\\`") {
			currentChar += string(originalWord[i+1]) + string(originalWord[i+2])
			i += 2
		}

		fmt.Printf("Current char: %v\n", currentChar)

		if dict[currentChar] != "" {

			nt.translatedWord += dict[currentChar]
		} else {
			nt.translatedWord += currentChar
		}
	}

	return nt.translatedWord
}

func (nt *NetTranslator) GetDictionary() map[string]string {

	unleetDictionary := map[string]string{"4": "A", "6": "B", "3": "E", "1": "I", "(V)": "M", "(\\)": "N", "0": "O", "5": "S", "7": "T", "\\/": "V", "`//": "W"}

	return unleetDictionary
}

func main() {
	nt := NewTranslator()

	fmt.Println(nt.FromL33t("570R(V)"))

}
