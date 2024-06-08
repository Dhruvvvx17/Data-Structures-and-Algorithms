#include<iostream>
#include<vector>
using namespace std;

class circularQueue {
private:
    int front;
    int rear;
    int capacity;
    int size;
    int *queue_array;

public:
    // constructor
    circularQueue(int capacity): front(-1), rear(-1), capacity(capacity), size(0) {
        if (capacity <= 0) {
            throw invalid_argument("Capacity must be positive");
        }
        queue_array = new int[capacity];
    }

    // method declarations
    void enqueue(int data);
    void dequeue();
    int peek();
    bool empty();
    bool full();
    void display();
    void reset();

    // destructor
    ~circularQueue() {
        cout<<"Destructor called | ";
        reset();
        delete queue_array;
        cout<<"Resources cleared"<<endl;
    }
};

void circularQueue::enqueue(int data) {
    if(full()) {
        cout<<"Queue overflow, cannot enqueue!"<<endl;
        return;
    }

    rear = (rear + 1) % capacity;
    if(empty()) front = rear;

    queue_array[rear] = data;
    size += 1;
    cout<<data<<" enqueued successfully to the rear of the queue"<<endl;
    return;
}

void circularQueue::dequeue() {
    if(empty()) {
        cout<<"Queue underflow, cannot dequeue"<<endl;
        return;
    }

    int x = queue_array[front];
    if(front == rear) front = -1;
    front = (front + 1) % capacity;
    size -= 1;
    cout<<x<<" dequeued from the front of the queue"<<endl;
    return;
}

int circularQueue::peek() {
    if(empty()) {
        cout<<"Queue underflow, cannot peek"<<endl;
        return -1;
    }
    
    int x = queue_array[front];
    cout<<"Element peeked at the front: "<<x<<endl;
    return x;
}

bool circularQueue::empty() {
    return size == 0;
}

bool circularQueue::full() {
    return size == capacity;
}

void circularQueue::display() {
    cout<<"Queue elements: ";
    int r = front;
    int i = 0;
    while(i < size){
        cout<<queue_array[r]<<" ";
        r = (r+1) % capacity;
        i += 1;
    }
    cout<<endl;
}

void circularQueue::reset() {
    front = -1;
    rear = -1;
    size = 0;
    cout<<"Queue reset"<<endl;
}

int main() {

    circularQueue queue = circularQueue(5);

    if(queue.empty()) cout<<"Queue is empty"<<endl;
    if(queue.full()) cout<<"Queue is full"<<endl;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    queue.enqueue(6);

    queue.display();

    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.display();


    queue.peek();

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    queue.display();

    queue.dequeue();
    queue.dequeue();

    queue.enqueue(100);
    queue.enqueue(200);
    queue.enqueue(300);

    queue.display();

    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();

    queue.peek();

    queue.enqueue(1000);
    queue.enqueue(2000);
    queue.enqueue(3000);

    queue.display();
    queue.reset();

    return 0;
}