#include<iostream>
#include<vector>
using namespace std;

class Stack {
    private:
        vector<int> stack;

    public:
        void push(int data);
        void pop();
        int top() const;
        void display();
        void clear();
        bool isEmpty() const;
};

void Stack::push(int data) {
    stack.push_back(data);
    cout<<data<<" pushed onto stack"<<endl;
}

void Stack::pop() {
    if(isEmpty()) {
        cout<<"Stack underflow"<<endl;
    } else {
        cout<<stack.back()<<" popped from the stack"<<endl;
        stack.pop_back();
    }
    return;
}

int Stack::top() const {
    if(isEmpty()) {
        cout<<"Stack underflow"<<endl;
        return -1;
    }
    cout<<"Stack top: "<<stack.back()<<endl;
    return stack.back();
}

bool Stack::isEmpty() const {
    if(stack.empty()) return true;
    return false;
}

void Stack::display() {
    if(isEmpty()) {
        cout<<"Stack underflow"<<endl;
        return;
    }

    cout<<"Stack elements: ";
    for(auto x: stack){
        cout<<x<<" ";
    }
    cout<<endl;
}

void Stack::clear() {
    stack.clear();
    cout<<"Stack cleared!"<<endl;
    return;
}
 
int main() {

    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    s.display();
    s.isEmpty();

    s.top();
    s.pop();
    s.top();
    s.pop();
    s.top();
    s.pop();
    s.top();
    s.pop();

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    s.clear();
    s.display();

    s.pop();
    s.top();
    
    return 0;
}