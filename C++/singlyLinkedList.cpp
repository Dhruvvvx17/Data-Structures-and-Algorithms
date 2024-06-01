#include<iostream>
#include<vector>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

    // constructor
    Node() : data(0), next(nullptr) {}

    Node(int data) : data(data), next(nullptr) {}
};

class List {
    public:
        Node* head;
        int length;
    
    // constructor
    List() : head(nullptr), length(0) {}

    // method declarations
    void insertBeginning(int data);
    void insertEnd(int data);
    void deleteBeginning();
    void deleteEnd();
    void insertAt(int data, int pos);
    void deleteAt(int pos);
    void reverse();
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
    head = newNode;
    length += 1;
    cout<<data<<" Inserted successfully"<<endl;
    return;
}

void List::insertEnd(int data) {
    Node *newNode = new Node(data);
    Node *p = head;

    if(p == nullptr) {
        head = newNode;
    }
    else {
        while(p->next != nullptr) {
            p = p->next;
        }
        p->next = newNode;
    }

    length += 1;
    cout<<data<<" Inserted successfully"<<endl;
    return;
}

void List::deleteBeginning() {
    if(length == 0) {
        cout<<"Empty Linked List!"<<endl;
        return;        
    }
    Node *p = head, *q;
    q = head;
    p = p->next;
    head = p;

    length -= 1;
    cout<<q->data<<" deleted successfully"<<endl;
    delete q;
    return;
}

void List::deleteEnd() {
    // empty list
    if(length == 0) {
        cout<<"Empty Linked List!"<<endl;
        return;        
    }

    // single node list
    if(length == 1) {
        Node *p = head;
        head = nullptr;
        length -= 1;
        cout<<p->data<<" deleted successfully"<<endl;
        delete p;
        return;
    }

    // general case
    Node *p = head, *q;
    q = head;
    p = p->next;

    while(p->next != nullptr) {
        p = p->next;
        q = q->next;
    }
    q->next = nullptr;

    length -= 1;
    cout<<p->data<<" deleted successfully"<<endl;
    delete p;
    return;    
}

void List::insertAt(int data, int pos) {
    if(pos < 0 || pos > length) {
        cout<<"Invalid position"<<endl;
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
    p->next = newNode;
    length += 1;
    cout<<newNode->data<<" inserted successfully"<<endl;
    return;
}

void List::deleteAt(int pos) {
    if(pos < 0 || pos > length) {
        cout<<"Invalid position"<<endl;
        return;
    }

    if(pos == 0) {
        deleteBeginning();
        return;
    }

    if(pos == length) {
        deleteEnd();
        return;
    }

    Node *p = head, *q;
    for(int i = 0; i < pos-1; ++i) {
        p = p->next;
    }

    q = p->next;
    p->next = q->next;
    length -= 1;
    cout<<q->data<<" deleted successfully"<<endl;
    delete q;
    return;
}

void List::reverse() {
    if(length == 0){
        cout<<"Empty Linked List!"<<endl;
        return;       
    }

    if(length == 1) {
        cout<<"Reversed | ";
        display();
        return;
    }

    Node *p, *q, *r;
    r = head;
    q = r->next;
    p = q->next;

    r->next = nullptr;
    while(p != nullptr) {
        q->next = r;
        r = q;
        q = p;
        p = p->next;
    }

    q->next = r;
    head = q;
    cout<<"Reversed | ";
    display();
    return;
}

void List::display() {

    if(length == 0) {
        cout<<"Empty Linked List!"<<endl;
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

void List::clear() {
    Node *p = head;
    Node *q = nullptr;
    while (p) {
        q = p->next; 
        delete p;           
        p = q; 
    }
    head = nullptr;
    length = 0;
    cout<<"Linked list cleared!"<<endl;
    return;
}

int main() {

    List list = List();

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

    return 0;
}