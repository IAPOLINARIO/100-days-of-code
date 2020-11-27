package main

import (
	"container/heap"
	"fmt"
	"strconv"
	"strings"
)

type Item struct {
	Value []byte
	Count int
}

func (t *Item) String() string {
	return fmt.Sprintf("%s:%d", string(t.Value), t.Count)
}

type PriorityQueue []*Item

func (pq PriorityQueue) Len() int      { return len(pq) }
func (pq PriorityQueue) Swap(a, b int) { pq[a], pq[b] = pq[b], pq[a] }
func (pq PriorityQueue) Less(a, b int) bool {
	// We want Pop to give us the highest, not lowest, priority so we use greater than here.
	return pq[a].Count > pq[b].Count
}

func (pq PriorityQueue) String() string {
	rst := make([]string, len(pq))
	for i := 0; i < len(pq); i++ {
		rst[i] = string(pq[i].Value) + ":" + strconv.Itoa(pq[i].Count)
	}
	return "[" + strings.Join(rst, ",") + "]"
}

func (pq *PriorityQueue) Push(x interface{}) {
	item := x.(*Item)
	*pq = append(*pq, item)
}

func (pq *PriorityQueue) Pop() interface{} {
	n := len(*pq)
	rst := (*pq)[n-1]
	// fmt.Println(pq)
	*pq = (*pq)[0 : n-1]
	return rst
}

func main() {
	fmt.Println(leastInterval([]byte("AAABBB"), 2))
}
func leastInterval(tasks []byte, n int) int {
	mfreq, size, rst := 0, 0, 0
	counters := [26]int{}
	for _, v := range tasks {
		var idx int
		if v >= 'a' && v < 'A' {
			idx = int(v - 'a')
		} else {
			idx = int(v - 'A')
		}
		counters[idx]++
		if counters[idx] == 1 {
			size++
		}
		if mfreq < counters[idx] {
			mfreq = counters[idx]
		}
	}
	// fmt.Println(size, mfreq)
	pq := make(PriorityQueue, size)
	for i, v := range counters {
		if v > 0 {
			pq[i] = &Item{[]byte(strconv.Itoa(i)), v}
		}
	}
	heap.Init(&pq)
	for len(pq) > 0 {
		interval_size := n + 1
		t := make([]*Item, 0)
		for interval_size > 0 && len(pq) > 0 {
			item := heap.Pop(&pq).(*Item)
			if item.Count > 0 {
				item.Count--
				if item.Count > 0 {
					t = append(t, item)
				}
				rst++
				interval_size--
				// fmt.Println(t, rst)
			}
		}
		for _, item := range t {
			heap.Push(&pq, item)
		}
		if len(pq) == 0 {
			break
		}
		if interval_size > 0 {
			rst += interval_size
		}
	}
	return rst
}
