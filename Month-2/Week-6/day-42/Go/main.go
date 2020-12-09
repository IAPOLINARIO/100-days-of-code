package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(minPages(5, 3))
}

func minPages(n, p float64) float64 {
	n /= 2
	p /= 2
	return math.Min(p, n-p)
}
