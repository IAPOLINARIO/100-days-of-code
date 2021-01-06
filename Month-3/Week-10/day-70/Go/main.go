package main

import (
	"fmt"
	"io/ioutil"
	"strings"
	"sync"
	"time"
)

const totalLines = 172820
const threads = 2

func main() {
	start := time.Now()

	brokenKeyboard := "poil"

	fmt.Printf("Result: %v\n", longestWord(brokenKeyboard))

	fmt.Printf("Execution time: %v\n", time.Since(start))
}

func longestWord(brokenKeyboard string) string {
	// A waitgroup to wait for all go-routines to finish.
	wg := sync.WaitGroup{}

	// This channel is used to send every read word in various go-routines.
	channel := make(chan (string))

	// A dictionary which stores the count of unique words.
	dict := make(map[string]int64)

	// Done is a channel to signal the main thread that all the words have been
	// entered in the dictionary.
	done := make(chan (bool), 1)

	// Read all incoming words from the channel and add them to the dictionary.
	go func() {
		for s := range channel {
			dict[s]++
		}
		// Signal the main thread that all the words have entered the dictionary.
		done <- true
	}()

	// Current signifies the counter for bytes of the file.
	var current int64

	// Limit signifies the chunk size of file to be proccessed by every thread.
	var chunk int64 = totalLines / threads
	var limit int64 = current + chunk

	for i := 0; i < threads; i++ {
		wg.Add(1)

		//fmt.Printf("Current: %d - Chunk: %d - Limit: %d \n", current, chunk, limit)

		go func(offset, pageLimit int64) {
			read(brokenKeyboard, offset, pageLimit, "../../../../assets/dictionary1.txt", channel)
			//	fmt.Printf("%d thread has been completed\n", i)
			wg.Done()
		}(current, limit)

		// Increment the current by 1+(last byte read by previous thread).
		current += chunk + 1
		limit = current + chunk
	}

	// Wait for all go routines to complete.ew
	wg.Wait()
	close(channel)

	// Wait for dictionary to process all the words.
	<-done
	close(done)

	longestWord := ""
	for w := range dict {
		if len(w) > len(longestWord) {
			longestWord = string(w)
		}
	}

	return longestWord

}

func read(brokenKeyboard string, offset int64, limit int64, fileName string, channel chan (string)) {
	rawBytes, err := ioutil.ReadFile(fileName)
	if err != nil {
		panic(err)
	}

	lines := strings.Split(string(rawBytes), "\n")
	for i, line := range lines {
		currentLine := strings.TrimSpace(string(line))
		validWord := true
		if int64(i) > offset && int64(i) <= limit {
			if currentLine != "" {
				for _, v := range currentLine {
					if !strings.ContainsRune(brokenKeyboard, v) {
						validWord = false
						break
					}
				}
				if validWord {
					// If the word matches the conditions, send it into the channel to enter the dictionary.
					channel <- currentLine
				}
			}
		}
	}

}
