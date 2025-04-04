#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

// Stack class
class Stack {
private:
    Node* top;
    int count;
    int maxSize;

public:
    // Constructor
    Stack(int size = 100) {
        top = NULL;
        count = 0;
        maxSize = size;
    }
    
    // Destructor to free memory
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
    
    // Push operation: Insert element into the top of Stack
    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push element " << value << endl;
            return;
        }
        
        // Create and initialize new node manually
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        count++;
        cout << value << " pushed to stack" << endl;
    }
    
    // Pop operation: Return top element from the Stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop from empty stack" << endl;
            return -1;
        }
        
        Node* temp = top;
        int poppedValue = temp->data;
        top = top->next;
        delete temp;
        count--;
        return poppedValue;
    }
    
    // Peek operation: Return the top element
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return top->data;
    }
    
    // Display operation: Print all elements of Stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        
        cout << "Stack elements: ";
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    
    // isEmpty operation: Check whether the stack is empty or not
    bool isEmpty() {
        return top == NULL;
    }
    
    // isFull operation: Check if there is a place to add an extra item or not
    bool isFull() {
        return count >= maxSize;
    }
    
    // Count operation: Return the count of stack items
    int getCount() {
        return count;
    }
    
    // Search operation: Search for a specific item in the stack
    bool search(int value) {
        if (isEmpty()) {
            return false;
        }
        
        Node* temp = top;
        while (temp != NULL) {
            if (temp->data == value) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
};

int main() {
    Stack stack;
    int choice, value;
    
    do {
        cout << "\n==== Stack Operations Menu ====\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "7. Count Items\n";
        cout << "8. Search Item\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: // Push
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                break;
                
            case 2: // Pop
                value = stack.pop();
                if (value != -1) {
                    cout << "Popped value: " << value << endl;
                }
                break;
                
            case 3: // Peek
                value = stack.peek();
                if (value != -1) {
                    cout << "Top element: " << value << endl;
                }
                break;
                
            case 4: // Display
                stack.display();
                break;
                
            case 5: // isEmpty
                if (stack.isEmpty()) {
                    cout << "Stack is empty" << endl;
                } else {
                    cout << "Stack is not empty" << endl;
                }
                break;
                
            case 6: // isFull
                if (stack.isFull()) {
                    cout << "Stack is full" << endl;
                } else {
                    cout << "Stack is not full" << endl;
                }
                break;
                
            case 7: // Count
                cout << "Number of items in stack: " << stack.getCount() << endl;
                break;
                
            case 8: // Search
                cout << "Enter value to search: ";
                cin >> value;
                if (stack.search(value)) {
                    cout << value << " found in the stack" << endl;
                } else {
                    cout << value << " not found in the stack" << endl;
                }
                break;
                
            case 0: // Exit
                cout << "Exiting program..." << endl;
                break;
                
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 0);
    
    return 0;
}
