package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

func CalculateTypeDistance(ip []string) string {
	r := []float64{3, 0, 0, 0, 1, 1, 1, 2, 2, 2, 3}
	c := []float64{1, 0, 1, 2, 0, 1, 2, 0, 1, 2, 0}

	sum := 0.
	a := 0.
	b := 0.

	for i := 0; i < len(ip); i++ {
		/* Let '.'-'0'= -2 -> 10 by adding and modding by 12.
		 * All others are equal to their digit value (e.g. 0 -> 0).
		 */
		ipChar, _ := strconv.Atoi(ip[i])
		j := (ipChar + 12) % 12
		x := r[j]
		y := c[j]

		if i > 0 {
			sum += math.Sqrt((a-x)*(a-x) + (b-y)*(b-y))
		}

		a = x
		b = y
	}

	return fmt.Sprintf("%.2fcm", sum)

}

func main() {

	input := "123654789"
	fmt.Print(CalculateTypeDistance(strings.Split(input, "")))
}
