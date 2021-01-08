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

	return nt.translatedWord
}

func (nt *NetTranslator) GetDictionary() map[string]string {

	leetDictionary := map[string]string{"0": "A", "1": "B"}

	return leetDictionary
}

func main() {
	//nt := NewTranslator()

	for k, v := range leetDictionary {

		fmt.Printf("k: %v, v:%v\n", k, v)
	}

}
