#include <iostream>
using namespace std;

// A Queue is a linear data structure that follows the FIFO principle — First In, First Out.
// This means the first element added to the queue will be the first one to be removed.

class Node {
    public:
    int data;
    Node *next;
    Node() {
        data = 0;
        next = NULL;
    }
};

class QueueWithLL {
private:
    int count = 0; // keep track of the number of elements in the queue

public:
    Node *front, *rear; // Pointers to the front and rear of the queue

    // Constructor: initializes the front and rear pointers to NULL
    QueueWithLL() {
        front = rear = NULL;
    }

    // Checks if the queue is empty
    bool IsEmpty() {
        return (front == NULL); // If front is NULL, the queue is empty
    }

    // Adds a new element to the end of the queue
    void Enqueue(int value) {
        Node *newNode = new Node(); // Create a new node
        newNode->data = value; // Assign value to the new node
        if (IsEmpty()) {
            front = rear = newNode; // Both front and rear point to the new node
            count++;
        } else { // If the queue already has elements
            rear->next = newNode; // Link new node to the current rear
            rear = newNode; // Update rear to point to the new node
            count++;
        }
    }

    // Displays all elements in the queue
    void Dispaly() {
        if (IsEmpty()) { // If queue is empty, print message and return
            cout << "Queue is empty." << endl;
            return;
        }
        Node *temp = front; // Temporary pointer to traverse the queue
        cout << "[ ";
        while (temp != NULL) { // Loop until the end of the queue
            cout << temp->data << " ";
            temp = temp->next; // Move to the next node
        }
        cout << "]" << endl;
        cout << "Count Of The Queue: " << count << endl;
    }

    // Removes and returns the front element from the queue
    int Dequeue() {
        if (IsEmpty()) {
            cout << "Queue is empty." << endl;
            return -1; // Return -1 or error value
        } else if (front == rear) { // If only one element in the queue
            delete front; // Delete the only node
            front = rear = NULL; // Reset both pointers
            count--;
        } else {
            Node *delPtr = front; // Save pointer to the front node
            int val = delPtr->data; // Save value to return
            front = front->next; // Move front pointer to next node
            delete delPtr; // Delete the old front node
            count--;
            return val; // Return deleted value
        }
    }

    // Checks if a value exists in the queue
    bool IsFound(int value) {
        if (IsEmpty()) {
            cout << "Queue is empty." << endl;
            return false;
        }
        Node *temp = front; // Temporary pointer to traverse the queue
        while (temp != NULL) {
            if (temp->data == value) { // If value is found
                return true;
            }
            temp = temp->next; // Move to next node
        }
        return false; // Value not found
    }

    // Deletes all elements from the queue
    void ClearAll() {
        if (IsEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        while (!IsEmpty()) { // Keep deleting until queue is empty
            Dequeue();
        }
    }

    // Returns the number of elements in the queue
    int Count() {
        return count;
    }

    // Returns the value at the front of the queue
    int GetFront() {
        return front->data;
    }

    // Returns the value at the rear of the queue
    int GetRear() {
        return rear->data;
    }
};


int main() {
    QueueWithLL q;

    q.Enqueue(5);
    q.Enqueue(10);
    q.Enqueue(15);
    cout << "Queue after enqueuing 5, 10, 15: ";
    q.Dispaly();

    cout << "Front Element: " << q.GetFront() << endl;
    cout << "Rear Element: " << q.GetRear() << endl;

    q.Dequeue();
    cout << "Queue after one dequeue: ";
    q.Dispaly();

    cout << "Is 10 found in queue? " << (q.IsFound(10) ? "Yes" : "No") << endl;
    cout << "Is 99 found in queue? " << (q.IsFound(99) ? "Yes" : "No") << endl;

    cout << "Number of elements: " << q.Count() << endl;

    q.ClearAll();
    cout << "Queue after clearing: ";
    q.Dispaly();

    return 0;
}
