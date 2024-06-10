package main

import (
	"fmt"
	"errors"
)

type circularQueue struct {
	front int
	rear int
	capacity int
	size int
	queue_array []int
}


func InitCircularQueue(capacity int) (*circularQueue, error) {
	if (capacity <= 0) {
		return nil, errors.New("Capacity must be positive, cannot create circular queue")
	}
	var queue *circularQueue = &circularQueue{}
	queue.front = -1
	queue.rear = -1
	queue.capacity = capacity
	queue.size = 0
	queue.queue_array = make([]int, capacity)
	return queue, nil
}


func (queue *circularQueue) Enqueue(data int) {
	if (queue.IsFull()) {
		fmt.Println("Queue overflow, cannot enqueue!")
		return
	}

	queue.rear = (1 + queue.rear) % queue.capacity
	queue.queue_array[queue.rear] = data

	if (queue.IsEmpty()) {
		queue.front = queue.rear
	}
	queue.size += 1
	fmt.Print(data, " enqueued to the rear of the queue\n")
	return
}

func (queue *circularQueue) Dequeue() {
	if (queue.IsEmpty()) {
		fmt.Println("Queue underflow, cannot dequeue")
		return
	}

	var x int = queue.queue_array[queue.front]
	if (queue.front == queue.rear) {
		queue.front = -1
	}
	queue.front = (queue.front + 1) % queue.capacity
	queue.size -= 1
	fmt.Print(x, " dequeued from the front of the queue\n")
	return
}

func (queue *circularQueue) Peek() (int, error) {
	if(queue.IsEmpty()) {
		return -1, errors.New("Queue underflow, cannot peek")
	}
	var x int = queue.queue_array[queue.front]
	return x, nil
}

func (queue *circularQueue) IsEmpty() bool {
	return queue.size == 0
}

func (queue *circularQueue) IsFull() bool {
	return queue.size == queue.capacity
}

func (queue *circularQueue) Display() {
	if(queue.IsEmpty()) {
		fmt.Println("Queue underflow, nothing to display")
		return
	}

	fmt.Print("Queue elements (front -> rear): ")
	for x,i := 0, queue.front; x < queue.size; i, x = (i+1)%queue.capacity, x + 1 {
		fmt.Print(queue.queue_array[i], " ")
	}
	fmt.Println()
}

func (queue *circularQueue) Clear() {
	
	queue.queue_array = nil
	queue.front = -1
	queue.rear = -1
	queue.size = 0
	fmt.Println("Queue cleared")
	return 
}

func main() {
	queue, err := InitCircularQueue(5)
	if (err != nil) {
		fmt.Println("Error: ", err)
		return
	}
	fmt.Println("Initial size: ", queue.size, " | Initial capacity: ", queue.capacity)

	queue.Enqueue(1)	
	queue.Enqueue(2)	
	queue.Enqueue(3)	
	queue.Enqueue(4)
	queue.Enqueue(5)
	queue.Enqueue(6)

	queue.Display()

	queue.Dequeue()
	queue.Dequeue()
	queue.Dequeue()

	queue.Display()
	x, err := queue.Peek()
	if(err != nil) {
		fmt.Println("Error: ", err)
	} else {
		fmt.Println("Peek element: ", x)
	}

	queue.Dequeue()
	queue.Dequeue()
	queue.Dequeue()

	queue.Display()
	x, err = queue.Peek()
	if(err != nil) {
		fmt.Println("Error: ", err)
	} else {
		fmt.Println("Peek element: ", x)
	}

	queue.Enqueue(10)	
	queue.Enqueue(20)	

	queue.Dequeue()

	queue.Enqueue(30)	
	queue.Enqueue(40)	

	queue.Dequeue()
	queue.Dequeue()

	queue.Display()
	x, err = queue.Peek()
	if(err != nil) {
		fmt.Println("Error: ", err)
	} else {
		fmt.Println("Peek element: ", x)
	}

	queue.Clear()
}