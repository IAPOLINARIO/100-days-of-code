package main

import "fmt"

func main() {
	fmt.Print(buildNumber())
}
func buildNumber() string {
	firstHalf := "...................."
	secondeHalf := "---------------------"

	return fmt.Sprintf("%v%v", len(firstHalf), len(secondeHalf))
}
