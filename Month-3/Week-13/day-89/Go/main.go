package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {

	fmt.Println(minutesBeforeNewYear("23 59"))

}

func minutesBeforeNewYear(input string) (result int) {

	timeArray := strings.Split(input, " ")
	hour, _ := strconv.Atoi(timeArray[0])
	minutes, _ := strconv.Atoi(timeArray[1])

	remainingHours := 23 - hour
	remainingMinutes := 60 - minutes

	result = (remainingHours * 60) + remainingMinutes
	return
}
