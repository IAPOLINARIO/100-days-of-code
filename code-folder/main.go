package main

import "fmt"

func main() {

	a, b := vals()
	fmt.Println(a)
	fmt.Println(b)

	_, c := vals()
	fmt.Println(c)

	d := sum(3, 5)
	fmt.Println(d)
}

func sum(a int, b int) int {

	return a + b
}

func vals() (int, int) {
	return 3, 7
}
