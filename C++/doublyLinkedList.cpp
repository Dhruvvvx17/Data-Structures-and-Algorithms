#include<iostream>
#include<vector>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node* prev;

    // constructor
    Node() : data(0), next(nullptr), prev(nullptr) {}

    Node(int data) : data(data), next(nullptr), prev(nullptr) {}
};

class List {
    public:
        Node* head;
        Node* tail;
        int length;
    
    // constructor
    List() : head(nullptr), tail(nullptr), length(0) {}

    // method declarations
    void insertBeginning(int data);
    void insertEnd(int data);
    void deleteBeginning();
    void deleteEnd();
    void insertAt(int data, int pos);
    void deleteAt(int pos);
    void reverse();
    void reverseDisplay();
    void display();
    void clear();

    // destructor
    ~List() {
        cout<<"Destructor called | ";
        clear();
    }
};

void List::insertBeginning(int data) {
    Node *newNode = new Node(data);
    newNode->next = head;
    newNode->prev = nullptr;

    if(length > 0) head->prev = newNode;
    head = newNode;

    if(length == 0) tail = newNode;

    length += 1;
    cout<<data<<" Inserted successfully at the beginning"<<endl;
    return;
}

void List::insertEnd(int data) {
    Node *newNode = new Node(data);
    newNode->prev = tail;
    newNode->next = nullptr;

    if(length > 0) tail->next = newNode;
    tail = newNode;

    if(length == 0) head = newNode;

    length += 1;
    cout<<data<<" Inserted successfully at the end"<<endl;
    return;
}

void List::deleteBeginning() {
    if(length == 0) {
        cout<<"Empty Linked List! Cannot perform delete"<<endl;
        return;        
    }

    Node *q;
    if(length == 1) {
        q = head;
        head = nullptr;
        tail = nullptr;
    }
    else {
        q = head;
        head = head->next;
        head->prev = nullptr;
    }

    length -= 1;
    cout<<q->data<<" deleted successfully from the beginning"<<endl;
    delete q;
    return;
}

void List::deleteEnd() {
    // empty list
    if(length == 0) {
        cout<<"Empty Linked List!"<<endl;
        return;        
    }

    Node *q;
    if(length == 1) {
        q = head;
        head = nullptr;
        tail = nullptr;        
    }
    else {
        q = tail;
        tail = tail->prev;
        tail->next = nullptr;
    }

    length -= 1;
    cout<<q->data<<" deleted successfully from the end"<<endl;
    delete q;
    return;    
}

void List::insertAt(int data, int pos) {
    if(pos < 0 || pos > length) {
        cout<<"Invalid position, cannot perform insert"<<endl;
        return;
    }

    if(pos == 0) {
        insertBeginning(data);
        return;
    }

    if(pos == length) {
        insertEnd(data);
        return;
    }

    Node *p = head;
    for(int i = 0; i < pos-1; ++i) {
        p = p->next;
    }
    Node *newNode = new Node(data);
    newNode->next = p->next;
    p->next->prev = newNode;

    p->next = newNode;    
    newNode->prev = p;

    length += 1;
    cout<<newNode->data<<" inserted successfully"<<endl;
    return;
}


void List::deleteAt(int pos) {
    if(pos < 0 || pos >= length) {
        cout<<"Invalid position, cannot perform delete"<<endl;
        return;
    }

    if(pos == 0) {
        deleteBeginning();
        return;
    }

    if(pos == length-1) {
        deleteEnd();
        return;
    }

    Node *p = head, *q;
    for(int i = 0; i < pos-1; ++i) {
        p = p->next;
    }

    // q will be deleted from the list
    q = p->next;
    p->next = q->next;
    q->next->prev = p;
    q->next = nullptr;
    q->prev= nullptr;

    length -= 1;
    cout<<q->data<<" deleted successfully"<<endl;
    delete q;
    return;
}


void List::reverse() {
    if(length == 0){
        cout<<"Empty Linked List! Cannot reverse."<<endl;
        return;       
    }

    if(length == 1) {
        cout<<"Reversed | ";
        display();
        return;
    }

    tail = head;
    Node *p, *q, *r;
    r = head;
    q = r->next;
    p = q->next;

    r->next = nullptr;
    while(p != nullptr) {
        q->next = r;
        r->prev = q;
        r = q;
        q = p;
        p = p->next;
    }

    q->next = r;
    r->prev = q;
    head = q;
    cout<<"Reversed | ";
    display();
    return;
}


void List::display() {

    if(length == 0) {
        cout<<"Empty Linked List! Nothing to display."<<endl;
        return;
    }

    Node *p = head;
    cout<<"List contains: ";
    while(p != nullptr){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<"| length = "<<length<<endl;
    return;
}

void List::reverseDisplay() {

    if(length == 0) {
        cout<<"Empty Linked List! Nothing to reverse display."<<endl;
        return;
    }

    Node *p = tail;
    cout<<"List contains: ";
    while(p != nullptr){
        cout<<p->data<<" ";
        p = p->prev;
    }
    cout<<"| length = "<<length<<endl;
    return;
}


void List::clear() {

    if(length == 0) {
        cout<<"Nothing to clear!"<<endl;
        return;
    }

    Node *p = head;
    Node *q = nullptr;
    while (p) {
        q = p->next;
        if(q) q->prev = nullptr;  // last node edge case
        p->next = nullptr;
        delete p;           
        p = q; 
    }
    head = nullptr;
    tail = nullptr;
    length = 0;
    cout<<"Linked list cleared!"<<endl;
    return;
}



int main() {

    List list = List();

    list.display();

    list.insertEnd(3);
    list.insertEnd(4);
    list.insertBeginning(2);
    list.insertBeginning(1);

    list.display();
    list.reverseDisplay();

    list.deleteEnd();
    list.deleteBeginning();
    list.deleteEnd();
    list.deleteBeginning();

    list.display();

    list.insertEnd(3);
    list.insertEnd(4);
    list.insertBeginning(2);
    list.insertBeginning(1);

    list.insertAt(100, 2);

    list.display();

    list.clear();

    list.insertAt(20, -5);
    list.insertAt(20, 5);
    list.insertAt(20, 0);   // beginning
    list.insertAt(40, 1);   // end
    list.insertAt(80, 2);   // end
    list.insertAt(60, 2);
    list.insertAt(100, 4);  // end
    list.insertAt(50, 2);

    list.display();

    list.deleteAt(-5);
    list.deleteAt(10);
    list.deleteAt(0);    // beginning
    list.deleteAt(4);    // end
    list.deleteAt(2);

    list.display();

    list.reverse();

    list.insertBeginning(1);
    list.insertEnd(100);
    list.insertAt(75, 3);

    list.display();

    list.reverse();

    list.deleteAt(3);

    list.clear();

    return 0;
}