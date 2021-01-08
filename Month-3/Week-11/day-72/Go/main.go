package main

import "fmt"

type NetTranslator struct {
	originalWord   string
	translatedWord string
}

func NewTranslator() *NetTranslator {
	return new(NetTranslator)
}

func (nt *NetTranslator) ToL33t(originalWord string) string {

	nt.originalWord = originalWord
	nt.translatedWord = ""
	dict := nt.GetDictionary()

	for _, c := range originalWord {

		if dict[string(c)] != "" {
			nt.translatedWord += dict[string(c)]
		} else {
			nt.translatedWord += string(c)
		}

	}

	return nt.translatedWord
}

func (nt *NetTranslator) GetDictionary() map[string]string {

	leetDictionary := map[string]string{"A": "4", "B": "6", "E": "3", "I": "1", "M": "(V)", "N": "(\\)", "O": "0", "S": "5", "T": "7", "V": "\\/", "W": "`//"}

	return leetDictionary
}

func main() {
	nt := NewTranslator()

	fmt.Println(nt.ToL33t("ELEET"))

}
