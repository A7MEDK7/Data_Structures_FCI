#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class QueueWithArray {
private:
    int rear, front, length; // rear: index of the last element, front: index of the first element, length: number of elements
    int arr[MAX_SIZE]; // Fixed-size array to hold queue elements

public:
    // Constructor: Initializes front, rear, and length
    QueueWithArray() {
        front = 0; // Start from index 0
        rear = MAX_SIZE - 1; // Rear starts at the last index to allow circular increment
        length = 0; // Initially, queue is empty
    }

    // Adds a new element at the rear of the queue
    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is full" << endl;
            return;
        }
        rear = (rear + 1) % MAX_SIZE; // Circular increment
        arr[rear] = item; // Add item at new rear position
        length++;
    }

    // Removes and returns the front element
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            int deletedValue = arr[front]; // Save front value
            front = (front + 1) % MAX_SIZE; // Move front to next position
            length--;
            return deletedValue;
        }
    }

    // Returns the value at the front without removing it
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            return arr[front]; // Return current front value
        }
    }

    // Returns the value at the rear without removing it
    int getRear() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            return arr[rear]; // Return current rear value
        }
    }

    // Displays all elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        for (int i = 0; i < length; i++) {
            cout << arr[(front + i) % MAX_SIZE] << " "; // Print elements in circular order
        }
        cout << "\nThe Size Of Queue IS: " << length << endl;
    }

    // Checks if a specific value exists in the queue
    bool isFound(int value) {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return false;
        }
        for (int i = 0; i < length; i++) {
            if (arr[(front + i) % MAX_SIZE] == value) {
                return true;
            }
        }
        return false;
    }

    // Checks if the queue is empty
    bool isEmpty() {
        return length == 0;
    }

    // Checks if the queue is full
    bool isFull() {
        return length == MAX_SIZE;
    }
};

int main() {
    QueueWithArray q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Queue after enqueue 10, 20, 30: ";
    q.display();

    cout << "Front element: " << q.getFront() << endl;
    cout << "Rear element: " << q.getRear() << endl;

    cout << "Dequeued: " << q.dequeue() << endl;
    q.display();

    cout << "Is 20 found? " << (q.isFound(20) ? "Yes" : "No") << endl;
    cout << "Is 99 found? " << (q.isFound(99) ? "Yes" : "No") << endl;

    return 0;
}
