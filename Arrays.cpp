#include <iostream>
#include <algorithm>
using namespace std;

class Array {
private:
    int size;
    int length;
    int* items;

public:
    Array(int arrsize) {
        size = arrsize;
        length = 0;
        items = new int[arrsize];
    }
    void Fill() {
        int no_of_items;
        cout << "Enter number of items: \n";
        cin >> no_of_items;
        if (no_of_items > size) {
            cout << "You Cannot Exceed The Array Size \n";
            return;
        }
        else {
            for (int i = 0; i < no_of_items; i++) {
                cout << "Enter Item Number: " << i + 1 << "\n";
                cin >> items[i];
                length++;
            }
        }
    }
    void Display() {
        cout << "\n Display Array Content: \n";
        for (int i = 0; i < length; i++) {
            cout << items[i] << " ";
        }
    }
    int GetSize() {
        return size;
    }
    int GetLength() {
        return length;
    }
    int Search(int key) {
        int index = -1;
        for (int i = 0; i < length; i++) {
            if (items[i] == key) {
                index = i;
                break;
            }
        }
        return index;
    }
    void Append(int newitem) {
        if (length < size) {
            items[length] = newitem;
            length++;
        }
        else {
            cout << "Array Full, You Cannot Add New Items! \n";
        }
    }
    void Insert(int index, int newitem) {
        if (index >= 0 && index < size) {
            for (int i = length; i > index - 1; i--) {
                items[i] = items[i - 1];
            }
            items[index - 1] = newitem;
            length++;
        }
        else {
            cout << "Array Full, You Cannot Add New Items! \n";
        }
    }
    void Remove(int index) {
        if (index >= 0 && index < length) {
            for (int i = index - 1; i < length - 1; i++) {
                items[i] = items[i + 1];
            }
            length--;
        }
        else {
            cout << "Index Out Of Array Range! \n";
        }
    }
    void Enlarge(int newsize) {
        if (size <= newsize) {
            size = newsize;
            int* old = items;
            items = new int[newsize];
            for (int i = 0; i < length; i++) {
                items[i] = old[i];
            }
            delete[] old;
        }
    }
    void Merge(Array other) {
        int newsize = size + other.GetSize();
        size = newsize;
        int* old = items;
        items = new int[newsize];
        int i;
        for (i = 0; i < length; i++) {
            items[i] = old[i];
        }
        delete[] old;
        int j = i;
        for (i = 0; i < other.GetLength(); i++) {
            items[j++] = other.items[i];
            length++;
        }
    }
};


int main() {
    // Create an array of size 10
    cout << "Creating an array of size 10..." << endl;
    Array myArray(10);
    
    // Fill the array with user input
    cout << "\n--- FILLING THE ARRAY ---" << endl;
    myArray.Fill();
    
    // Display array content
    myArray.Display();
    
    // Get and display array properties
    cout << "\n\n--- ARRAY PROPERTIES ---" << endl;
    cout << "Size: " << myArray.GetSize() << endl;
    cout << "Length: " << myArray.GetLength() << endl;
    
    // Test search function
    cout << "\n--- TESTING SEARCH ---" << endl;
    int searchKey;
    cout << "Enter a value to search for: ";
    cin >> searchKey;
    int searchResult = myArray.Search(searchKey);
    if (searchResult != -1) {
        cout << searchKey << " found at index " << searchResult << endl;
    } else {
        cout << searchKey << " not found in the array" << endl;
    }
    
    // Test append function
    cout << "\n--- TESTING APPEND ---" << endl;
    int appendValue;
    cout << "Enter a value to append: ";
    cin >> appendValue;
    myArray.Append(appendValue);
    cout << "After appending " << appendValue << ":";
    myArray.Display();
    
    // Test insert function
    cout << "\n\n--- TESTING INSERT ---" << endl;
    int insertIndex, insertValue;
    cout << "Enter position to insert at (1-based): ";
    cin >> insertIndex;
    cout << "Enter value to insert: ";
    cin >> insertValue;
    myArray.Insert(insertIndex, insertValue);
    cout << "After inserting " << insertValue << " at position " << insertIndex << ":";
    myArray.Display();
    
    // Test remove function
    cout << "\n\n--- TESTING REMOVE ---" << endl;
    int removeIndex;
    cout << "Enter position to remove (1-based): ";
    cin >> removeIndex;
    myArray.Remove(removeIndex);
    cout << "After removing element at position " << removeIndex << ":";
    myArray.Display();
    
    // Test enlarge function
    cout << "\n\n--- TESTING ENLARGE ---" << endl;
    int newSize;
    cout << "Enter new size for the array: ";
    cin >> newSize;
    myArray.Enlarge(newSize);
    cout << "Array size increased to " << myArray.GetSize() << endl;
    cout << "Array content remains:";
    myArray.Display();
    
    // Test merge function
    cout << "\n\n--- TESTING MERGE ---" << endl;
    int secondArraySize;
    cout << "Enter size for second array: ";
    cin >> secondArraySize;
    Array secondArray(secondArraySize);
    cout << "Filling the second array:" << endl;
    secondArray.Fill();
    
    cout << "Second array content:";
    secondArray.Display();
    
    cout << "\nMerging arrays..." << endl;
    myArray.Merge(secondArray);
    cout << "After merging:";
    myArray.Display();
    
    cout << "\n\nFinal array properties:" << endl;
    cout << "Size: " << myArray.GetSize() << endl;
    cout << "Length: " << myArray.GetLength() << endl;
    
    return 0;
}
