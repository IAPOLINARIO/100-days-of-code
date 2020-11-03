package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Node struct {
	key   int
	left  *Node
	right *Node
}

func NewNode(value int) *Node {
	n := new(Node)
	n.key = value
	n.left = nil
	n.right = nil

	return n
}

func main() {

	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of nodes:")

	input, _ := reader.ReadString('\n')

	nodes, _ := strconv.Atoi(strings.TrimSpace(input))

	tree := buildTree(1, nodes)

	fmt.Printf("Number of possible combinations: %v \n", len(tree))

}

func buildTree(start int, end int) (tree []Node) {

	if start > end {
		tree = append(tree, Node{})
		return tree
	}

	for i := start; i <= end; i++ {
		/* constructing left subtree */
		leftSubtree := buildTree(start, i-1)

		/* constructing right subtree */
		rightSubtree := buildTree(i+1, end)

		/* connecting both sides of the tree
		   them to ith root below */
		for j := 0; j < len(leftSubtree); j++ {
			left := leftSubtree[j]

			for k := 0; k < len(rightSubtree); k++ {
				right := rightSubtree[k]

				// making value i as root
				node := NewNode(i)

				// connect left node
				node.left = &left

				// connect right node
				node.right = &right

				// Add this node to the tree
				tree = append(tree, *node)
			}
		}
	}

	return tree
}
