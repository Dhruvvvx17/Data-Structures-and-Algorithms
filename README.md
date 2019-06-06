# Data-Structures-and-Algorithms
Implementation of some widely used **Data Structures** and **Algorithms** in C.

#### Data Structures:

  1. Singly Linked List
  2. Doubly Linked List
  3. Stacks
  4. Infix to Postfix (using stacks)
  5. Expression Trees (using stacks and trees)
  6. Bracket Validity (using stacks)
  7. Circular Queue
  8. DFS and BFS using Adjacecy Matrix
  9. Binary Search Tree using Linked list (insertion, deletion and traversal)
  10. Binary Search Tree using Array (insertion and traversal only)
  11. Heap using array (Max heap)
  12. Priority queue (Max heap approach)
  13. Trie (Insertion, Deletion and Search)
  14. Hash Table (Linear probing implementation - Insertion and Search)

#### Algorithms:

  1. Linear Search
  2. Binary Search
  3. Bubble Sort
  4. Selection Sort
  5. Merge Sort
  6. Quick Sort
  7. Insertion Sort
  8. Heap Sort
  9. Distribution Counting Sort
  10. Naive String Matching
  11. Horspool's String Matching
---

## Data Structures:
*a data structure is a data organization, management, and storage format that enables efficient access and modification*

- ### Linked Lists:
A **Linked List** is a linear collection of data elements, whose order is not given by their physical placement in memory. Instead, each element points to the next. It is a data structure consisting of a collection of nodes which together represent a sequence. In its most basic form, each node contains: data, and a reference (in other words, a link/pointer) to the next node in the sequence.

Advantage of linked list over arrays is that linked lists are variable size hence, no restriction on number of elements at any point of time. Disadvantage of linked list over arrays is that random access is not possible in linked list.

**Efficiency of different operations on linked list:**
  - Insertion (beginning/end)          - O(1)
  - Insertion (at specified position)  - O(n)
  - Deletion (beginning/end)           - O(1)
  - Deletion (at specified position)   - O(n)
  - Search                             - O(n)
  
---

- ### Stacks:
A **Stack** is an abstract data type that serves as a collection of elements, with two principal operations: **push**, which adds an element to the collection, and **pop**, which removes the most recently added element. Stacks follow the LIFO (Last In First Out) methodology.

**Efficiency of different operations on stacks:**
  - Push   - O(1)
  - Pop    - O(1)
  
(assuming array implementation or linked list with pointer for a the top of the stack)

**Various applications of stacks:**
  - Infix to postfix conversion
  - Bracket validity
  - Expression evaluation
  
---

- ### Queues:
**Queue** is an abstract data structure, somewhat similar to Stacks. Unlike stacks, a queue is open at both its ends. One end is always used to insert data (enqueue) and the other is used to remove data (dequeue). Queue follows FIFO (First In First Out) methodology, i.e., the data item stored first will be accessed first.

**Efficiency of different operations on queues:**
  - Push   - O(1)
  - Pop    - O(1)

(assuming array implementation or linked list with pointer for a the front and read end of the queue)

**Various applications of queues:**
  - Disk Scheduling
  - asynchronous data transfer between two processes 
  - Priority queue

---

- ### Graphs:
 A **graph** is a pictorial representation of a set of objects where some pairs of objects are connected by links. The interconnected objects are termed as vertices, and the links that connect the vertices are called edges. The breadth first search (BFS) and the depth first search (DFS) are the two algorithms used for traversing and searching a node in a graph. They can also be used to find out whether a node is reachable from a given node or not.

**Efficiency of different operations on graphs:**
  - Efficiency of BFS & DFS (adjacency matrix)   - O(|V|<sup>2</sup>)
  - Efficiency of BFS & DFS (adjacency list)     - O(|V|x|E|)

**Various applications of graphs:**
  - Represents flow of computation
  - Resource allocation graph in OS
 
 ---

- ### Tree:
A **tree** is a widely used abstract data type that simulates a hierarchical tree structure, with a root value and subtrees of children with a parent node, represented as a set of linked nodes. It can also be interpreted as an acyclic graph. Most common type of trees includes Binary search tree, heap tree, AVL tree, B tree, 2-3 tree, Red-Black tree etc.

**Efficiency of different operations on BST:**
  - Efficiency of Insertion/Deletion/Searching (worst case)   - O(n)
  - Efficiency of Insertion/Deletion/Searching (average case)   - O(log(n))

**Various applications of trees:**
  - Efficiently storing data
  - Evaluating arithmetic expressions

---

- ### Trie:
A **trie** also called digital tree, radix tree or prefix tree, is a kind of search tree — an ordered tree data structure used to store a dynamic set or associative array where the keys are usually strings.

**Efficiency of different operations on trie:**
  - Efficiency of Insertion/Deletion/Searching (worst case)   - O(n * m)

**Various applications of trie:**
  - Auto completing words
  - Spell checkers

---

- ### Hash Table:
A **hash table** s a data structure that implements an associative array abstract data type, a structure that can map keys to values. A hash table uses a hash function to compute an index into an array of buckets or slots, from which the desired value can be found.

**Efficiency of different operations on hash table:**
  - Efficiency of Insertion/Deletion/Searching (worst case)   - O(n)
  - Efficiency of Insertion/Deletion/Searching (best case)    - O(1)
  
**Various applications of hash table:**
  - Password Verification
  - Compiler operations

---


14.Hash Table (Linear probing implementation - Insertion and Search)

### Algorithms:

1.Linear Search

2.Binary Search

3.Bubble Sort

4.Selection Sort

5.Merge Sort

6.Quick Sort

7.Insertion Sort

8.Heap Sort

9.Distribution Counting Sort

10.Naive String Matching

11.Horspool's String Matching
