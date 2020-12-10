package main

import (
	"bufio"
	"fmt"
	"io/ioutil"
	"os"
	"strconv"
	"strings"
)

const (
	dictionarySize            = 256
	compressedExtension       = "-compressed.isma"
	uncompressedFileExtension = "-uncompressed"
)

func main() {
	baseFilePath := "./assets/lero_lero_1-5MB.txt"

	uncompressLZW(baseFilePath, compressedExtension)

}

func compressLZW(filePath string) {
	code := dictionarySize
	dictionary := make(map[string]int)

	for i := 0; i < dictionarySize; i++ {
		dictionary[fmt.Sprint(i)] = i
	}

	currChar := ""
	fileContent := readFile(filePath)

	result := make([]int, 0)
	for _, c := range []byte(fileContent) {
		phrase := currChar + string(c)

		if _, isTrue := dictionary[phrase]; isTrue {
			currChar = phrase
		} else {
			result = append(result, dictionary[currChar])
			dictionary[phrase] = code
			code++
			currChar = string(c)
		}
	}

	if currChar != "" {
		result = append(result, dictionary[currChar])
	}

	compressedFilePath := fmt.Sprintf("%v%v", filePath, compressedExtension)
	writeFile(result, compressedFilePath)
	fmt.Println("File compressed")

}

func uncompressLZW(baseFilePath string, fileExtension string) {

	compressedFilePath := fmt.Sprintf("%v%v", baseFilePath, fileExtension)
	fileToDecompress := readFile(compressedFilePath)

	compressed := parseByteArrayToIntArray(fileToDecompress)

	code := dictionarySize
	dictionary := make(map[int]string)
	for i := 0; i < 256; i++ {
		dictionary[i] = fmt.Sprint(i)
	}

	currChar := fmt.Sprint(compressed[0])
	result := currChar
	for _, element := range compressed[1:] {
		var word string
		if x, ok := dictionary[element]; ok {
			word = x
		} else if element == code {
			word = currChar + currChar[:1]
		} else {
			panic(fmt.Sprintf("Bad compressed element: %d", element))
		}

		result += word

		dictionary[code] = currChar + word[:1]
		code++

		currChar = word
	}

	writeUncompressedFile(result, fmt.Sprintf("%v%v", baseFilePath, uncompressedFileExtension))
	fmt.Println("File uncompressed !")

}

func writeUncompressedFile(content string, filePath string) {
	err := ioutil.WriteFile(filePath, []byte(content), 0644)

	checkError(err)
}

func checkError(e error) {
	if e != nil {
		panic(e)
	}
}

func parseByteArrayToIntArray(byteArray []byte) []int {
	stringArray := strings.Split(string(byteArray), " ")
	result := make([]int, len(stringArray))

	for i := 0; i < len(stringArray); i++ {
		currentValue := strings.ReplaceAll(strings.ReplaceAll(stringArray[i], "[", ""), "]", "")
		result[i], _ = strconv.Atoi(currentValue)
	}

	return result
}

func readFile(filePath string) []byte {
	fileContent, err := ioutil.ReadFile(filePath)
	checkError(err)

	return fileContent
}
func writeFile(content []int, filePath string) {

	f, err := os.Create(filePath)
	checkError(err)

	defer f.Close()

	w := bufio.NewWriter(f)
	data, err := w.WriteString(fmt.Sprint(content))
	checkError(err)
	fmt.Printf("wrote %d bytes\n", data)

	w.Flush()
}
