#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Linkedlist {
public:
    Node* head;

    Linkedlist() {
        head = NULL;
    }

    bool isEmpty() {
        return (head == NULL);
    }

    void insertNew(int newValue) {
        // Create New Node and Set Its Data Value
        Node* newNode = new Node();
        newNode->data = newValue;
        // Check If There Is Nodes In Linked List Or It Is Empty 
        if (isEmpty()) {
            newNode->next = NULL;
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    int count() {
        int counter = 0;
        Node* temp = head;
        while (temp != NULL) {
            counter++;
            temp = temp->next;
        }
        return counter;
    }

    bool isFound(int dataValue) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == dataValue) {
                return true;
            } else {
                temp = temp->next;
            }
        }
        return false;
    }

    void insertBefore(int item, int newValue) {
        if (isEmpty()) {
            insertNew(newValue);
        } 
        
        if (isFound(item)) {
            Node* newNode = new Node();
            newNode->data = newValue;
            Node* temp = head;
            while (temp != NULL && temp->next->data != item) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        } 
        else {
            cout << "Sorry, This Item Not Found! \n";
        }
    }

    void append(int newValue) {
        if (isEmpty()) {
            insertNew(newValue);
        }
        else {
            Node* newNode = new Node();
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            newNode->data = newValue;
            temp->next = newNode;
            newNode->next = NULL;
        }
    }

    void deleteItem(int key) {
        // Check if the list is empty
        if (isEmpty()) {
            cout << "The List Is Empty, No Item To Delete! \n";
            return; // Exit the function since there's nothing to delete
        }

        // Create a pointer that will point to the node we want to delete
        Node* del_ptr = head;

        // Special case: If the key is in the head node
        if (head->data == key) {
            // Update head to point to the second node
            head = head->next;
            // Free the memory of the old head node
            delete del_ptr;
        }
        else {
            // We need to find the node to delete
            // prv_ptr will keep track of the node before the one we want to delete
            Node* prv_ptr = NULL;
            del_ptr = head;

            // Traverse the list until we find the node with the target key
            while (del_ptr->data != key) {
                // Update previous pointer to current node
                prv_ptr = del_ptr;
                // Move to the next node
                del_ptr = del_ptr->next;
            }

            // Update the previous node's next pointer to skip the node we're deleting
            prv_ptr->next = del_ptr->next;
            // Free the memory of the node we want to delete
            delete del_ptr;
        }
    }
};


int main() {
    Linkedlist list;
    if (list.isEmpty()) {
        cout << "The List Is Empty \n";
    } else {
        cout << "The List Has:" << list.count() << "Data \n";
    }

    int newData1;
    cout << "Enter New Data To Add: \n";
    cin >> newData1;
    list.insertNew(newData1);
    cout << "==== List Content ====" << "\n";
    list.display();
    cout << "\n======================\n";

    int newData2;
    cout << "Enter New Data To Add: \n";
    cin >> newData2;
    list.insertNew(newData2);
    cout << "==== List Content ====" << "\n";
    list.display();
    cout << "\n======================\n";


    int newData3;
    cout << "Enter New Data To Add: \n";
    cin >> newData3;
    list.insertNew(newData3);
    cout << "==== List Content ====" << "\n";
    list.display();
    cout << "\n======================\n";


    int newData4;
    cout << "Enter New Data To Add: \n";
    cin >> newData4;
    list.insertNew(newData4);
    cout << "==== List Content ====" << "\n";
    list.display();
    cout << "\n======================\n";

    if (list.isEmpty()) {
        cout << "The List Is Empty \n";
    } else {
        cout << "The List Has: " << list.count() << " Data \n";
    }

    int key;
    cout << "Enter Value To Search: \n";
    cin >> key;
    if (list.isFound(key)) {
        cout << key << " Is Found \n";
    } else {
        cout << key << " Not Found \n";
    }

    int newData5,otherData;
    cout << "Enter Item To Insert Before It: \n";
    cin >> otherData;
    cout << "Enter New Data To Add: \n";
    cin >> newData5;
    list.insertBefore(otherData, newData5);
    cout << "==== List Content ====" << "\n";
    list.display();
    cout << "\n======================\n";

    int newData6;
    cout << "Enter New Data To Append: \n";
    cin >> newData6;
    list.append(newData6);
    cout << "==== List Content ====" << "\n";
    list.display();
    cout << "\n======================\n";

    int newData7;
    cout << "Enter Item To Delete: \n";
    cin >> newData7;
    list.deleteItem(newData7);
    cout << "==== List Content ====" << "\n";
    list.display();
    cout << "\n======================\n";
    
}
