package main

import "fmt"

type Stall struct {
	left  int64
	right int64
}

func main() {

	input := [][]int64{{4, 2}, {5, 2}, {6, 2}, {1000, 1000}, {1000, 1}}

	checkStalls(input)
}

func checkStalls(input [][]int64) {

	for k, v := range input {
		s := solve(v[0], v[1])
		if s.right < s.left {
			fmt.Printf("CASE #%d: %d %d\n", k, s.left, s.right)
		} else {
			fmt.Printf("CASE #%d: %d %d\n", k, s.right, s.left)
		}
	}
}

func solve(N int64, K int64) (result Stall) {

	result = placeOne(N)
	for K > 1 {
		if K%2 == 0 {
			result = placeOne(result.right)
			K /= 2
		} else {
			result = placeOne(result.left)
			K = (K - 1) / 2
		}
	}
	return result
}

func placeOne(N int64) (result Stall) {

	if N%2 == 0 {
		result.left = N/2 - 1
		result.right = N / 2
	} else {
		result.left = (N - 1) / 2
		result.right = (N - 1) / 2
	}
	return result
}
