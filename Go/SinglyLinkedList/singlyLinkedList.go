package main

import "fmt"

type Node struct {
	data int
	next *Node
}

type List struct {
	head *Node
	length int
}


func initList() *List {
	var list *List = &List{}
	list.head = nil
	list.length = 0
	return list
}


func (list *List) insertBeginning(data int) {
	var newNode *Node = &Node{data: data, next: list.head}
	list.head = newNode
	list.length += 1
	fmt.Println(data, "Inserted successfully")
	return
}


func (list *List) insertEnd(data int) {
	var newNode *Node = &Node{data: data, next: nil}
	if (list.length == 0) {
		list.head = newNode
	} else {
		var p *Node = list.head
		for (p.next != nil) {
			p = p.next
		}
		p.next = newNode
	}	
	list.length += 1
	fmt.Println(data, "Inserted successfully")
	return
}


func (list *List) deleteBeginning() {
	if (list.length == 0) {
		fmt.Println("Empty linked list, nothing to delete")
		return
	}

	var p *Node = list.head
	list.head = list.head.next
	list.length -= 1

	fmt.Println(p.data,"Deleted successfully")
	p = nil	// marked for the GC
	return 
}


func (list *List) deleteEnd() {
	if(list.length == 0) {
		fmt.Println("Empty linked list, nothing to delete")
		return
	}

	if(list.length == 1) {
		var p *Node = list.head
		list.head = nil
		list.length -= 1
		fmt.Println(p.data,"Deleted successfully")
		p = nil // marked for the GC
		return	
	}

	var p *Node = list.head
	q := p
	for (p.next != nil) {
		q = p
		p = p.next
	}
	q.next = nil
	list.length -= 1

	fmt.Println(p.data,"Deleted successfully")
	p = nil // marked for the GC
	return
}


func (list *List) insertAt(data int, pos int) {
	if(pos < 0 || pos > list.length) {
		fmt.Println("Invalid position to insert at")
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
	var newNode *Node = &Node{data: data, next: nil}
	newNode.next = p.next
	p.next = newNode
	list.length += 1
	fmt.Println(data, "Inserted successfully")
	return
}


func (list *List) deleteAt(pos int) {
	if(pos < 0 || pos > list.length) {
		fmt.Println("Invalid position to delete at")
		return
	}

	if(pos == 0) {
		list.deleteBeginning()
		return
	}

	if(pos == list.length) {
		list.deleteEnd()
		return
	}

	var p *Node = list.head
	for i := 0; i < pos-1; i++ {
		p = p.next
	}

	q := p.next
	p.next = q.next
	list.length -= 1
	fmt.Println(q.data, "Deleted successfully")
	q = nil
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

	r := list.head
	q := r.next
	p := q.next

	r.next = nil
	for (p != nil) {
		q.next = r
		r = q
		q = p
		p = p.next
	}

	q.next = r
	list.head = q
	fmt.Print("Reversed | ")
	list.display()
	return
}


func (list *List) display() {
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

    list.display();

    list.insertEnd(4);
    list.insertBeginning(1);
    list.insertAt(2,1);
    list.insertAt(3,2);

    list.display();
    list.reverse();

    list.clear();

    list.insertEnd(4);
    list.insertBeginning(1);
    list.insertAt(2,1);
    list.insertAt(3,2);

    list.display();

    list.deleteAt(10);
    list.deleteBeginning();
    list.reverse();
    list.deleteEnd();

    list.deleteAt(0);
    list.deleteAt(0);

    list.reverse();
    list.clear();
}