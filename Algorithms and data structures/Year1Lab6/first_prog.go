package main

import (
	"bufio"
	"fmt"
	"os"
)

type Tree struct {
	root   *Node
	height int
}

func (tree Tree) AddRoot(key int) Tree {
	tree.root = &Node{key: key, index: 0}
	return tree
}

func (tree Tree) BuildTree(node *Node, index int, list [][]int) Tree {
	left := list[index][1] - 1
	right := list[index][2] - 1
	if left != -1 {
		temp := &Node{key: list[left][0], index: left}
		node.left = temp
		tree = tree.BuildTree(temp, left, list)
	}
	if right != -1 {
		temp := &Node{key: list[right][0], index: right}
		node.right = temp
		tree = tree.BuildTree(temp, right, list)
	}
	return tree
}

func (tree Tree) Balance(node *Node, result []int) (Tree, []int) {
	if node.left == nil && node.right == nil {
		node.balance = 0
		node.height = 1
		result[node.index] = node.balance
		return tree, result
	}
	var leftHeight, rightHeight int
	if node.left != nil {
		tree, result = tree.Balance(node.left, result)
		leftHeight = node.left.height
	} else {
		leftHeight = 0
	}
	if node.right != nil {
		tree, result = tree.Balance(node.right, result)
		rightHeight = node.right.height
	} else {
		rightHeight = 0
	}
	node.height = Max(leftHeight, rightHeight) + 1
	node.balance = rightHeight - leftHeight
	result[node.index] = node.balance
	return tree, result
}

func Max(a int, b int) int {
	if a >= b {
		return a
	} else {
		return b
	}
}

type Node struct {
	key     int
	balance int
	height  int
	index   int
	left    *Node
	right   *Node
}

func main() {
	in, out := bufio.NewReader(os.Stdin), bufio.NewWriter(os.Stdout)
	var n, key, left, right int
	list := make([][]int, 0)
	fmt.Fscanln(in, &n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &key)
		fmt.Fscan(in, &left)
		fmt.Fscan(in, &right)
		temp := []int{key, left, right}
		list = append(list, temp)
	}
	var tree Tree
	result := make([]int, n)
	tree = tree.AddRoot(list[0][0])
	tree = tree.BuildTree(tree.root, 0, list)
	tree, result = tree.Balance(tree.root, result)
	for i := 0; i < n; i++ {
		fmt.Fprintln(out, result[i])
	}
	out.Flush()
}
