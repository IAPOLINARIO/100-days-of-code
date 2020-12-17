package main

import (
	"fmt"
	"os"
	"reflect"
	"testing"
)

func Test_File_1(t *testing.T) {
	baseFilePath := "./assets/lero_lero_short.txt"
	originalFileStat, _ := os.Stat(baseFilePath)
	expectedResult := originalFileStat.Size()

	compressLZW(fmt.Sprintf("%v", baseFilePath))
	uncompressLZW(baseFilePath, compressedExtension)

	uncompressedFileStat, _ := os.Stat(fmt.Sprintf("%v%v", baseFilePath, uncompressedFileExtension))

	result := uncompressedFileStat.Size()

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_File_2(t *testing.T) {
	baseFilePath := "./assets/lero_lero_1-5MB.txt"
	originalFileStat, _ := os.Stat(baseFilePath)
	expectedResult := originalFileStat.Size()

	compressLZW(fmt.Sprintf("%v", baseFilePath))
	uncompressLZW(baseFilePath, compressedExtension)

	uncompressedFileStat, _ := os.Stat(fmt.Sprintf("%v%v", baseFilePath, uncompressedFileExtension))

	result := uncompressedFileStat.Size()

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_File_3(t *testing.T) {
	baseFilePath := "./assets/lero_lero_153kb.txt"
	originalFileStat, _ := os.Stat(baseFilePath)
	expectedResult := originalFileStat.Size()

	compressLZW(fmt.Sprintf("%v", baseFilePath))
	uncompressLZW(baseFilePath, compressedExtension)

	uncompressedFileStat, _ := os.Stat(fmt.Sprintf("%v%v", baseFilePath, uncompressedFileExtension))

	result := uncompressedFileStat.Size()

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}

func Test_Image_1(t *testing.T) {
	baseFilePath := "../../../../assets/MARBLES.BMP"
	originalFileStat, _ := os.Stat(baseFilePath)
	expectedResult := originalFileStat.Size()

	compressLZW(fmt.Sprintf("%v", baseFilePath))
	uncompressLZW(baseFilePath, compressedExtension)

	uncompressedFileStat, _ := os.Stat(fmt.Sprintf("%v%v", baseFilePath, uncompressedFileExtension))

	result := uncompressedFileStat.Size()

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
