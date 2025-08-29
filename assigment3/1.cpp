#include <iostream>
using namespace std;

#define MAX 5

int stack[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1) {
        cout << "Stack overflow" << endl;
    } else {
        stack[++top] = x;
        cout << x << "pushed into stack" << endl;
    }
}

void pop() {
    if (top == -1) {
        cout << "Stack undrflow" << endl;
    } else {
        cout << stack[top--] << " popped from stack" << endl;
    }
}

void isEmpty() {
    if (top == -1)
        cout << "Stack is Empty" << endl;
    else
        cout << "Stack is not Empty" << endl;
}

void isFull() {
    if (top == MAX - 1)
        cout << "stack is full" << endl;
    else
        cout << "Stack is not full." << endl;
}

void display() {
    if (top == -1) {
        cout << "stack is empty." << endl;
    } else {
        cout << "stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

void peek() {
    if (top == -1) {
        cout << "stack is empty" << endl;
    } else {
        cout << "top elemtn" << stack[top] << endl;


    }
}
int main(){
    int ch,val;
    while(1){
        cout<<"\n1.Push\n2.Pop\n3.isEmpty\n4.isFull\n5.Display\n6.Peek\n7.Exit\n";
        cout<<"Enter choice";
        cin>>ch;
        switch(ch){
            case 1: cout<<"Enter value: ";cin>>val;push(val);break;
            case 2: pop();break;
            case 3: isEmpty();break;
            case 4: isFull();break;
            case 5: display();break;
            case 6: peek();break;
            case 7: return 0;
            default: cout<<"Invalid choice"<<endl;
        }

    }
}
