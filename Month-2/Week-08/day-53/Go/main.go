package main

import (
	"fmt"
	"math"
)

const (
	gravity = 9.81
)

func main() {
	speed := 36.7
	angle := 45.

	Ymax, Xmax := javelinThrow(speed, angle)

	fmt.Printf("%v,%v \n", Ymax, Xmax)
}

func javelinThrow(speed float64, angle float64) (string, string) {
	angleInRadians := angle * (math.Pi / 180)
	speedY := speed * math.Sin(angleInRadians)
	Y := math.Pow(speedY, 2) / (2 * gravity)

	time := 2 * speedY / gravity
	speedX := speed * math.Cos(angleInRadians)
	X := 0 + speedX*time

	return fmt.Sprintf("Ymax=%vm", int(Y)), fmt.Sprintf("Xmax=%vm", int(X))
}
