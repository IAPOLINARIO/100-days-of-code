package main

import "fmt"

func main() {
	input1 := []float64{2, 4, 1000000000}
	input2 := []float64{2, 4, 15000000000}
	input3 := []float64{2, 4, 184000000000000000000000000}

	fmt.Println(rabbitSwarm(input1))
	fmt.Println(rabbitSwarm(input2))
	fmt.Println(rabbitSwarm(input3))
}

type rabbit struct {
	male, female, all float64
}

func rabbitSwarm(input []float64) (months, dead float64) {
	initialRabbit := rabbit{input[0], input[1], input[0] + input[1]}
	var arrRabbits [96]rabbit
	var allRabbits = arrRabbits[:]
	allRabbits[1] = initialRabbit
	total := initialRabbit.all
	dead = 0
	for months = 0; total < input[2]; months++ {
		var fertile = allRabbits[4:]
		newRabbits := rabbit{}
		for i := 0; i < len(fertile); i++ {
			newRabbits.female += fertile[i].female * 9
			newRabbits.male += fertile[i].female * 5
		}
		newRabbits.all += newRabbits.female + newRabbits.male
		//Remove dead rabbits
		total -= allRabbits[95].all
		dead += allRabbits[95].all
		//Add new rabbits
		total += newRabbits.all
		// Remove the last element from the array (Rabbits have died)
		allRabbits = allRabbits[:len(allRabbits)-1]
		// Insert the newest element to the front of the array (Rabbits are born)
		allRabbits = append([]rabbit{newRabbits}, allRabbits...)
	}
	return months - 1, dead
}
