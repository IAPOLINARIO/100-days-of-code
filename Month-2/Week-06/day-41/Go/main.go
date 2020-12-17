package main

import "fmt"

func main() {
	input := []int{1, 2, 1, 2, 1, 3, 2}
	fmt.Println(sockPairs(input))
}

func sockPairs(socks []int) int {
	pairs := 0
	var socksMap = make(map[int]int)

	for _, sock := range socks {

		if socksMap[sock] == 1 {
			pairs++
			socksMap[sock] = 0
		} else {
			socksMap[sock] = socksMap[sock] + 1
		}
	}
	return pairs
}
