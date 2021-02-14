package main

import "fmt"

var dollarBills = [5]int{1, 5, 10, 20, 100}

func main() {

	fmt.Println(withdraw(125))
	fmt.Println(withdraw(43))
	fmt.Println(withdraw(1000000000))
	fmt.Println(withdraw(515))

}

func withdraw(amount int) (result int) {

	remainder := amount
	for i := len(dollarBills) - 1; i >= 0; i-- {

		quotient := remainder / dollarBills[i]
		remainder -= quotient * dollarBills[i]
		result += quotient

		if remainder == 0 {
			return
		}
	}

	return
}
