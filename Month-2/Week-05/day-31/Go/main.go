package main

import (
	"fmt"
)

func main() {
	result := timeInWords(5, 15)

	fmt.Println(result)
}

func timeInWords(h, m int) (result string) {
	switch {
	case m == 0:
		result = fmt.Sprintf("%s o' clock", toWords(h))
	case m == 15:
		result = fmt.Sprintf("Quarter past %s", toWords(h))
	case m < 30:
		s := ""
		if m > 1 {
			s = "s"
		}
		result = fmt.Sprintf("%s minute%s past %s", toWords(m), s, toWords(h))
	case m == 30:
		result = fmt.Sprintf("Half past %s", toWords(h))
	case m == 45:
		result = fmt.Sprintf("Quarter to %s", toWords(h+1))
	default:
		s := ""
		if 60-m > 1 {
			s = "s"
		}
		result = fmt.Sprintf("%s minute%s to %s", toWords(60-m), s, toWords(h+1))
	}

	return result
}

func toWords(m int) string {
	dict := map[int]string{
		1:  "one",
		2:  "two",
		3:  "three",
		4:  "four",
		5:  "five",
		6:  "six",
		7:  "seven",
		8:  "eight",
		9:  "nine",
		10: "ten",
		11: "eleven",
		12: "twelve",
		13: "thirteen",
		14: "fourteen",
		15: "fifteen",
		16: "sixteen",
		17: "seventeen",
		18: "eighteen",
		19: "nineteen",
		20: "twenty",
		30: "thirty",
		40: "forty",
		50: "fifty",
	}
	if m <= 20 {
		return dict[m]
	} else {
		return fmt.Sprintf("%s %s", dict[m/10*10], dict[m%10])
	}
}
