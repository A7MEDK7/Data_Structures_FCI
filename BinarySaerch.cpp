#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(int arr[], int l, int h, int key) {
    while (l <= h) {
        int mid = (l + h) / 2;
        if (arr[mid] == key) return mid;
        if (arr[mid] > key) {
            h = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return -1;
}


int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int key;
    cout << "Enter a number to search for: ";
    cin >> key;
    
    int result = binarySearch(arr, 0, n-1, key);
    
    if (result == -1)
        cout << "Element " << key << " not found in the array" << endl;
    else
        cout << "Element " << key << " found at index " << result << endl;
    
    return 0;
}
