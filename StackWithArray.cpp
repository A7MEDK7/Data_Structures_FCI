#include <iostream>
#include <stack>
using namespace std;

// Stack With Array
// A Stack is a linear data structure that follows the LIFO principle — Last In, First Out.
// This means the last element added to the stack will be the first one to be removed.

// Fixed Size For Stack
const int MAX_SIZE = 100;

class Stack {
private:
    int top; // Keeps track of the index of the top element in the stack
    int item[MAX_SIZE]; // Array to store stack elements (fixed size)

public:
    // Constructor: initializes the stack by setting top to -1 (means empty stack)
    Stack() {
        top = -1;
    }

    // Adds an element to the top of the stack
    void push(int element) {
        if (top == MAX_SIZE - 1) { // Check if the stack is full
            cout << "Stack overflow" << endl;
            return; 
        }
        top++; // Move top pointer to the next position
        item[top] = element; // Store the new element at the top
    }

    // Removes the top element from the stack
    void pop() {
        if (isEmpty()) { 
            cout << "Stack underflow" << endl;
            return; 
        }
        top--; // Simply decrease the top index to "remove" the element
    }

    // Removes and returns the top element from the stack
    int popWithSaveValue() {
        if (isEmpty()) {
            cout << "Stack underflow" << endl;
            return 0; 
        }
        int val = item[top]; // Save the current top element
        top--; // Decrease the top index
        return val; // Return the saved element
    }

    // Returns the top element without removing it
    int getTop() {
        if (isEmpty()) {
            cout << "Stack underflow" << endl;
            return 0; 
        }
        return item[top];
    }

    // Displays all elements in the stack from bottom to top
    void display() {
        if (isEmpty()) { 
            cout << "Stack underflow" << endl;
            return;
        }
        cout << "[ ";
        for (int i = 0; i <= top; i++) {
            cout << item[i];
            if (i != top) cout << ", ";
        }
        cout << " ]" << endl;
    }

    // Checks whether the stack is empty
    bool isEmpty() {
        return top == -1; // If top == -1, the stack has no elements
    }
};

int main() {
    Stack s;

    // Push elements to the stack
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Stack after pushing 10, 20, 30: ";
    s.display();  // Expected: [ 10, 20, 30 ]

    // Get top element
    cout << "Top element: " << s.getTop() << endl;  // Expected: 30

    // Pop one element
    s.pop();
    cout << "Stack after one pop: ";
    s.display();  // Expected: [ 10, 20 ]

    // Push more elements
    s.push(40);
    s.push(50);
    cout << "Stack after pushing 40, 50: ";
    s.display();  // Expected: [ 10, 20, 40, 50 ]

    // Pop with saving value
    int poppedValue = s.popWithSaveValue();
    cout << "Popped element (with save): " << poppedValue << endl;  // Expected: 50
    cout << "Stack after popWithSaveValue(): ";
    s.display();  // Expected: [ 10, 20, 40 ]

    // Check if stack is empty
    cout << "Is the stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
