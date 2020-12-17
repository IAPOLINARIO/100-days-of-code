package main

import (
	"bufio"
	"fmt"
	"log"
	"math"
	"os"
	"strconv"
	"strings"
)

type animal struct {
	XYpair
	speed float64
}
type XYpair struct {
	x, y float64
}

func (c XYpair) Dot(d XYpair) float64 {
	return c.x*d.x + c.y*d.y
}

func (c XYpair) Norm() float64 {
	return math.Hypot(c.x, c.y)
}

func (c XYpair) Diff(d XYpair) XYpair {
	return XYpair{c.x - d.x, c.y - d.y}
}

func gopherEscapePlan(dog, gopher animal, gHoles []XYpair) {
	catch := intercept(dog, gopher, nearest(gopher, gHoles))
	if catch == nil {
		fmt.Println("Gopher got away.")
	}
	fmt.Println(catch.x, catch.y)
}

func main() {

	filePath := "..\\..\\..\\..\\assets\\day-35_sample_1_valid.txt"
	parseFile(filePath)
}

func parseFile(filePath string) error {
	var dog, gopher animal
	rolesQty := 0
	variableSetLineNumber := 0
	roleIndex := 0
	isFileInvalid := true

	f, err := os.Open(filePath)

	if err != nil {
		log.Fatal(err)
	}

	defer f.Close()

	scanner := bufio.NewScanner(f)

	for scanner.Scan() {
		textLine := scanner.Text()
		tokens := strings.Split(textLine, " ")

		if variableSetLineNumber == 0 {
			if tokens[0] == "" || tokens[1] == "" || tokens[2] == "" || tokens[3] == "" || tokens[4] == "" {
				fmt.Printf("%v\n", "BAD FILE!")
				return fmt.Errorf("%v", "BAD FILE!")

			} else {
				rolesQty, _ = strconv.Atoi(tokens[0])
				gopher.x, _ = strconv.ParseFloat(tokens[1], 64)
				gopher.y, _ = strconv.ParseFloat(tokens[2], 64)
				dog.x, _ = strconv.ParseFloat(tokens[3], 64)
				dog.y, _ = strconv.ParseFloat(tokens[4], 64)

				fmt.Printf("Gopher roles: %v, Gopher.X: %v, Gopher.Y: %v, Dog.X:%v, Dog.Y: %v \n", rolesQty, gopher.x, gopher.y, dog.x, dog.y)

				variableSetLineNumber++
			}
		} else if textLine != "" && variableSetLineNumber > 0 {
			gHoles := make([]XYpair, rolesQty)
			gHoles[roleIndex].x, _ = strconv.ParseFloat(tokens[0], 64)
			gHoles[roleIndex].y, _ = strconv.ParseFloat(tokens[1], 64)

			fmt.Printf("Role number: %v, role.X: %v, role.Y: %v\n", roleIndex, gHoles[roleIndex].x, gHoles[roleIndex].y)
			fmt.Printf("Text line: %v \n", textLine)

			if (roleIndex + 1) == rolesQty {
				isFileInvalid = false
				gopherEscapePlan(dog, gopher, gHoles)
			} else {
				roleIndex++
				variableSetLineNumber++
			}

		} else if textLine == "" {
			variableSetLineNumber = 0
			roleIndex = 0

		}

	}

	if isFileInvalid {
		fmt.Printf("%v\n", "BAD FILE!")
		return fmt.Errorf("%v", "BAD FILE!")
	}

	return nil

	//	gopherEscapePlan(pupper, gopher)
}

func nearest(gopher animal, holeList []XYpair) (tgt XYpair) {
	var dist float64
	for i, h := range holeList {
		x, y := gopher.x-h.x, gopher.y-h.y
		tmp := math.Sqrt(float64(x*x + y*y))
		if i == 0 || tmp < dist {
			dist, tgt = tmp, h
		}
	}
	return tgt
}

func intercept(p, g animal, tgt XYpair) (xy *XYpair) {
	pg, tg := p.Diff(g.XYpair), tgt.Diff(g.XYpair)
	gVel := XYpair{g.speed * tg.x / g.Norm(), g.speed * tg.y / g.Norm()}
	arrTime := tgt.Diff(g.XYpair).Norm() / g.speed

	a := g.speed*g.speed - p.speed*p.speed
	b := -2 * gVel.Dot(pg)
	c := pg.Dot(pg)
	time1 := (-b + math.Sqrt(b*b-4*a*c)) / (2 * a)
	time2 := (-b - math.Sqrt(b*b-4*a*c)) / (2 * a)

	catchTime := time1
	if time2 > catchTime {
		catchTime = time2
	}

	if catchTime < 0 || catchTime > arrTime {
		return nil
	}
	return &XYpair{g.x + gVel.x*catchTime, g.y + gVel.y*catchTime}
}
