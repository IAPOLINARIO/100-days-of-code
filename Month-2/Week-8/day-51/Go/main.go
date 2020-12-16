package main

import (
	"fmt"
)

type Asteroid struct {
	Size      int
	Direction int //1= Positive (moving to the right) / -1=Negative (moving to the left)
}

func NewAsteroid(size int) *Asteroid {
	a := new(Asteroid)
	a.Size = size

	if size > 0 {
		a.Direction = 1
	} else {
		a.Direction = -1
	}
	return a
}

func main() {
	input := []int{8, -8}
	exploded := checkExplodedAsteroids(input)
	fmt.Println(getBiggestAsteroid(input, exploded))

}

func getBiggestAsteroid(originalAsteroidSet, resultAsteroidSet []int) (result []int) {

	for i := 0; i < len(originalAsteroidSet); i++ {
		asteroidExploded := false
		for j := 0; j < len(resultAsteroidSet); j++ {

			if originalAsteroidSet[i] == resultAsteroidSet[j] {
				asteroidExploded = true
				break
			}
		}
		if !asteroidExploded {
			result = append(result, originalAsteroidSet[i])
		}
	}
	return
}

func checkExplodedAsteroids(asteroids []int) (explodedAsteroids []int) {
	currentAsteroid := NewAsteroid(asteroids[len(asteroids)-1])
	for i := len(asteroids) - 2; i >= 0; i-- {
		nextAsteroid := NewAsteroid(asteroids[i])
		if currentAsteroid.Direction != nextAsteroid.Direction { //asteroids will collide
			smallesAsteroid := getSmallestAsteroid(currentAsteroid, nextAsteroid)
			if smallesAsteroid != nil {
				explodedAsteroids = append(explodedAsteroids, smallesAsteroid.Size)
			} else {
				explodedAsteroids = append(explodedAsteroids, currentAsteroid.Size)
				explodedAsteroids = append(explodedAsteroids, nextAsteroid.Size)
			}
		}
	}

	return
}

func getSmallestAsteroid(currentAsteroid, nextAsteroid *Asteroid) *Asteroid {
	currentAsteroidSize := currentAsteroid.Size * currentAsteroid.Direction
	nextAsteroidSize := nextAsteroid.Size * nextAsteroid.Direction

	if currentAsteroidSize > nextAsteroidSize {
		return nextAsteroid
	} else if currentAsteroidSize < nextAsteroidSize {
		return currentAsteroid
	}

	return nil
}
