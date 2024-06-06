package main

import (
	"fmt"
	"errors"
	"sync"
)

type Stack struct {
	elements []int
	size int
	access sync.Mutex
}

func InitStack() *Stack {
	var stack *Stack = &Stack{}
	stack.elements = []int{}
	stack.size = 0
	return stack
}

func (stack *Stack) Push(data int) {
	stack.access.Lock()
	defer stack.access.Unlock()

	stack.elements = append(stack.elements, data)
	stack.size += 1
	fmt.Println(data, "pushed onto stack")
}

func (stack *Stack) Pop() (int, error) {
	stack.access.Lock()
	defer stack.access.Unlock()

	if(stack.IsEmpty()) {
		return 0, errors.New("Stack underflow, cannot pop")
	}
	popped_element := stack.elements[stack.size - 1]
	stack.elements = stack.elements[:stack.size - 1]
	stack.size -= 1
	return popped_element, nil
}

func (stack *Stack) Peek() (int, error){
	stack.access.Lock()
	defer stack.access.Unlock()

	if(stack.IsEmpty()) {
		return 0, errors.New("Stack underflow, nothing to peek")
	}

	top_element := stack.elements[stack.size - 1]
	return top_element, nil
}

func (stack *Stack) Display() {
	stack.access.Lock()
	defer stack.access.Unlock()

	if(stack.IsEmpty()) {
		fmt.Println("Stack underflow, nothing to display")
		return
	}
	fmt.Print("Stack elements: ")
	for i := 0; i < stack.size; i++ {
		fmt.Print(stack.elements[i]," ")
	}
	fmt.Println()
	return
}

func (stack *Stack) Clear() {
	stack.access.Lock()
	defer stack.access.Unlock()

	stack.elements = []int{}
	stack.size = 0
	fmt.Println("stack cleared!")
	return
}

// can't make it thread safe -> deadlock
func (stack *Stack) IsEmpty() bool {
	return stack.size == 0
}


func main() {
	var stack *Stack = InitStack()
	fmt.Println("Initial Length: ", stack.size)

	stack.Push(10)
	stack.Push(20)
	stack.Push(30)
	stack.Push(40)

	stack.Display()
	stack.IsEmpty()

	var top int
	var popped int
	var empty bool
	var err error

	top, err = stack.Peek()
	if (err != nil){
		fmt.Println("error: ", err)
	} else {
		fmt.Println("Top element: ", top)
	}

	popped, err = stack.Pop()
	if (err != nil){
		fmt.Println("error: ", err)
	} else {
		fmt.Println("Popped element: ", popped)
	}
	
	top, err = stack.Peek()
	if (err != nil){
		fmt.Println("error: ", err)
	} else {
		fmt.Println("Top element: ", top)
	}

	popped, err = stack.Pop()
	if (err != nil){
		fmt.Println("error: ", err)
	} else {
		fmt.Println("Popped element: ", popped)
	}

	top, err = stack.Peek()
	if (err != nil){
		fmt.Println("error: ", err)
	} else {
		fmt.Println("Top element: ", top)
	}

	popped, err = stack.Pop()
	if (err != nil){
		fmt.Println("error: ", err)
	} else {
		fmt.Println("Popped element: ", popped)
	}

	top, err = stack.Peek()
	if (err != nil){
		fmt.Println("error: ", err)
	} else {
		fmt.Println("Top element: ", top)
	}

	popped, err = stack.Pop()
	if (err != nil){
		fmt.Println("error: ", err)
	} else {
		fmt.Println("Popped element: ", popped)
	}


	empty = stack.IsEmpty()
	fmt.Println("Stack empty: ", empty)

	stack.Push(10)
	stack.Push(20)
	stack.Push(30)
	stack.Push(40)

	stack.Clear()
	stack.Display()

	top, err = stack.Peek()
	if (err != nil){
		fmt.Println("error: ", err)
	} else {
		fmt.Println("Top element: ", top)
	}

	popped, err = stack.Pop()
	if (err != nil){
		fmt.Println("error: ", err)
	} else {
		fmt.Println("Popped element: ", popped)
	}
}