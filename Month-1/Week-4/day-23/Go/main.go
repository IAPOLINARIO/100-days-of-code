package main

import (
	"fmt"
	"time"
)

type Philosopher struct {
	id            int
	name          string
	forkAvailable chan bool
	neighbor      *Philosopher
	eatQty        int
}

func MakePhilosopher(id int, name string, neighbor *Philosopher) *Philosopher {
	p := &Philosopher{id, name, make(chan bool, 1), neighbor, 0}
	p.forkAvailable <- true

	return p
}

func (p *Philosopher) eat(operation *[]string) {
	p.eatQty += 1
	*operation = append(*operation, fmt.Sprintf("[%v,%v,%v]", p.id, 0, 3))
	//fmt.Printf("%v is eating. \n", p.name)
	//time.Sleep(time.Duration(rand.Int63n(1e9)))
	time.Sleep(1 * time.Millisecond)
	//fmt.Printf("%v has eaten %v times\n", p.name, p.eatQty)
}

func (p *Philosopher) think() {
	//fmt.Printf("%v is thinking.\n", p.name)
	time.Sleep(1 * time.Millisecond)
	//time.Sleep(time.Duration(rand.Int63n(1e9)))
}

func (phil *Philosopher) getForks(operation *[]string) {
	// Declare a channel for timeout
	timeout := make(chan bool, 1)

	//go func() { time.Sleep(1e9); timeout <- true }()
	go func() { time.Sleep(1 * time.Millisecond); timeout <- true }()
	// taking the philosopher fork; then fork is not available anymore
	<-phil.forkAvailable
	*operation = append(*operation, fmt.Sprintf("[%v,%v,%v]", phil.id, 1, 1))
	//fmt.Printf("%v got his fork. \n", phil.name)
	select {
	// if the neighbor's fork is availble, return, ready to eat
	case <-phil.neighbor.forkAvailable:
		*operation = append(*operation, fmt.Sprintf("[%v,%v,%v]", phil.id, 2, 1))
		//fmt.Printf("%v got %v's fork.\n", phil.name, phil.neighbor.name)
		//fmt.Printf("%v has two fork.\n", phil.name)
		return

	// after amount of time the philosopher taking up his own fork, the
	// philosopher has to put the fork down letting others to use
	// then think for a while and try get fork operation again
	case <-timeout:
		phil.forkAvailable <- true
		*operation = append(*operation, fmt.Sprintf("[%v,%v,%v]", phil.id, 1, 2))
		phil.think()
		phil.getForks(operation)
	}
}

func (phil *Philosopher) returnForks(operation *[]string) {
	// after a philosopher finish eating, making his fork channel
	// and his neighbor's fork channel demeonstrate available again
	*operation = append(*operation, fmt.Sprintf("[%v,%v,%v]", phil.id, 1, 2))
	*operation = append(*operation, fmt.Sprintf("[%v,%v,%v]", phil.id, 2, 2))
	phil.forkAvailable <- true
	phil.neighbor.forkAvailable <- true
}

func (phil *Philosopher) dine(announce chan *Philosopher, dineQty int, output *[]string) {
	// the whole procedure of dining
	for i := 0; i < dineQty; i++ {
		phil.think()
		phil.getForks(output)
		phil.eat(output)
		phil.returnForks(output)
	}
	phil.think()
	announce <- phil
}

func main() {
	names := []string{"Ismael", "Canova", "Joao", "Dito", "Monan", "Clemente", "Gian", "Evandro"}
	dineEachePhilosopher := 100
	output, timesEaten := startTheDiner(names, dineEachePhilosopher)

	fmt.Printf("%v\n", *output)
	fmt.Printf("Each philosopher have eaten %v times\n", timesEaten)
}

func startTheDiner(philosopherNames []string, servingPerPhilosopher int) (*[]string, int) {
	output := []string{}
	philosophers := make([]*Philosopher, len(philosopherNames))
	var phil *Philosopher
	// link all philosophers together
	for i, name := range philosopherNames {
		phil = MakePhilosopher(i, name, phil)
		philosophers[i] = phil
	}
	// let the first philosopher to be the neighbor of the last philosopher
	philosophers[0].neighbor = phil
	//fmt.Printf("There are %v philosophers sitting at the table.\n", len(names))
	//fmt.Println("They each have one fork, and must borrow from their neighbor to eat.")
	announce := make(chan *Philosopher)
	for _, phil := range philosophers {
		// dine occur concurrently
		go phil.dine(announce, servingPerPhilosopher, &output)
	}

	// the announce channel will get the philosophers who finish dining sequentially in concurrent dine()
	// print out them concurrently
	// for i := 0; i < len(names); i++ {
	// 	phil := <-announce
	// 	fmt.Printf("%v is done dining. \n", phil.name)
	// }

	<-announce
	fmt.Printf("Ate %v times \n", phil.eatQty)
	return &output, phil.eatQty
}
