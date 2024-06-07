package main

import "fmt"

type Node struct {
	data int
	next *Node
	prev *Node
}

type List struct {
	head *Node
	tail *Node
	length int
}


func initList() *List {
	var list *List = &List{}
	list.head = nil
	list.tail = nil
	list.length = 0
	return list
}


func (list *List) insertBeginning(data int) {
	var newNode *Node = &Node{data: data, next: list.head, prev: nil}

	if(list.length > 0) {
		list.head.prev = newNode
	} 

	list.head = newNode

	if list.length == 0 {
		list.tail = newNode
	}

	list.length += 1
	fmt.Println(data, "Inserted successfully at the beginning")
	return
}


func (list *List) insertEnd(data int) {
	var newNode *Node = &Node{data: data, next: nil, prev: list.tail}

	if(list.length > 0) {
		list.tail.next = newNode
	}

	list.tail = newNode

	if list.length == 0 {
		list.head = newNode
	}

	list.length += 1
	fmt.Println(data, "Inserted successfully at the end")
	return
}


func (list *List) deleteBeginning() {
	if (list.length == 0) {
		fmt.Println("Empty linked list, nothing to delete")
		return
	}

	var p *Node = list.head
	if (list.length == 1) {
		list.head = nil
		list.tail = nil
	} else {
		list.head = list.head.next
		list.head.prev = nil
	}

	list.length -= 1
	fmt.Println(p.data,"Deleted successfully from the beginning")
	p = nil	// marked for the GC
	return 
}


func (list *List) deleteEnd() {
	if(list.length == 0) {
		fmt.Println("Empty linked list, nothing to delete")
		return
	}

	var p *Node = list.tail
	if(list.length == 1) {
		list.head = nil
		list.tail = nil
	} else {
		list.tail = list.tail.prev
		list.tail.next = nil
	}

	list.length -= 1
	fmt.Println(p.data,"Deleted successfully from the end")
	p = nil // marked for the GC
	return
}


func (list *List) insertAt(data int, pos int) {
	if(pos < 0 || pos > list.length) {
		fmt.Println("Invalid position, cannot perform insert")
		return
	}

	if(pos == 0) {
		list.insertBeginning(data)
		return
	}

	if(pos == list.length) {
		list.insertEnd(data)
		return
	}

	var p *Node = list.head
	for i := 0; i < pos-1; i++ {
		p = p.next
	}

	var newNode *Node = &Node{data: data, next: nil, prev: nil}
	newNode.next = p.next
	newNode.prev = p

	p.next = newNode
	newNode.next.prev = newNode

	list.length += 1
	fmt.Println(data, "Inserted successfully")
	return
}


func (list *List) deleteAt(pos int) {
	if(pos < 0 || pos >= list.length) {
		fmt.Println("Invalid position, cannot perform delete")
		return
	}

	if(pos == 0) {
		list.deleteBeginning()
		return
	}

	if(pos == list.length - 1) {
		list.deleteEnd()
		return
	}

	var p *Node = list.head
	for i := 0; i < pos-1; i++ {
		p = p.next
	}

	q := p.next
	p.next = q.next
	q.next.prev = p
	q.next = nil
	q.prev = nil

	list.length -= 1
	fmt.Println(q.data, "Deleted successfully")
	q = nil // marked for the GC
	return
}


func (list *List) reverse() {
	if (list.length == 0) {
		fmt.Println("Empty linked list, nothing to delete")
		return		
	}

	if (list.length == 1) {
		fmt.Print("Reversed | ")
		list.display()
		return
	}

	list.tail = list.head
	r := list.head
	q := r.next
	p := q.next

	r.next = nil
	for (p != nil) {
		q.next = r
		r.prev = q
		r = q
		q = p
		p = p.next
	}

	q.next = r
	r.prev = q
	list.head = q
	fmt.Print("Reversed | ")
	list.display()
	return
}


func (list *List) display() {

	if (list.length == 0) {
		fmt.Println("Empty Linked List! Nothing to display.")
		return
	}

	var p *Node = list.head
	fmt.Print("Linked List: ")
	for (p != nil) {
		fmt.Print(p.data," -> ")
		p = p.next
	}
	fmt.Print("nil | Length: ", list.length,"\n")
	return
}

func (list *List) clear() {
	p := list.head
	q := list.head
	for (p != nil) {
		q = p.next
		p = nil // mark for cleanup by GC
		p = q
	}

	// reset
	list.head = nil
	list.length = 0
	fmt.Println("Linked list cleared")
	return
}

func main() {
	var list *List = initList()
	fmt.Println("Initial Length: ", list.length)

    list.display()
	
	list.insertEnd(3)
	list.insertEnd(4)
	list.insertBeginning(2)
	list.insertBeginning(1)
	
    list.display()
	
	list.deleteEnd()
	list.deleteBeginning()
	list.deleteEnd()
	list.deleteBeginning()

	list.display()

	list.insertEnd(3)
	list.insertEnd(4)
	list.insertBeginning(2)
	list.insertBeginning(1)

	list.insertAt(100, 2)

	list.display()

	list.clear()

	list.insertAt(20, -5)
    list.insertAt(20, 5)
    list.insertAt(20, 0)   // beginning
    list.insertAt(40, 1)   // end
    list.insertAt(80, 2)   // end
    list.insertAt(60, 2)
    list.insertAt(100, 4)  // end
    list.insertAt(50, 2)

    list.display()

    list.deleteAt(-5)
    list.deleteAt(10)
    list.deleteAt(0)    // beginning
    list.deleteAt(4)    // end
    list.deleteAt(2)

    list.display()

    list.reverse()

    list.insertBeginning(1)
    list.insertEnd(100)
    list.insertAt(75, 3)

    list.display()

    list.reverse()

    list.deleteAt(3)

    list.clear()


}