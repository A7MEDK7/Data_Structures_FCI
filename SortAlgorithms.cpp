#include <iostream>
#include <algorithm>
using namespace std;

void insertionSort(int arr[], int n) {
    int key, j;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void selectionSort(int arr[], int n) {
    int minIndex;
    for (int i = 0; i < n - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr, minIndex, i);
    }
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr, j, j + 1);
            }
        }
    }
}

int partition(int arr[], int iBegin, int jEnd) {
    int pivot = arr[iBegin];  // Using first element as pivot
    int i = iBegin + 1;
    int j = jEnd;
    while (true) {
        // Find element greater than or equal to pivot from left
        while (i <= j && arr[i] < pivot) {
            i++;
        }
        // Find element less than pivot from right
        while (i <= j && arr[j] > pivot) {
            j--;
        }
        // If indices crossed, partition is done
        if (i > j) {
            break;
        }
        // Swap elements
        swap(arr, i, j);
        i++;
        j--;
    }
    // Put pivot in its final sorted position
    swap(arr, iBegin, j);
    // Return pivot location
    return j;
}

void quickSort(int arr[], int i, int h) {
    if (i < h) {
        // Partition the array
        int pivLocation = partition(arr, i, h);
        // Recursively sort elements before and after partition
        quickSort(arr, i, pivLocation - 1);
        quickSort(arr, pivLocation + 1, h);
    }
}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int* Left = new int[n1], * Right = new int[n2];

    for (i = 0; i < n1; i++) {
        Left[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        Right[j] = arr[m + 1 + j];  // Corrected: m + 1 + j instead of m + l + j
    }

    i = j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (Left[i] <= Right[j]) {
            arr[k] = Left[i];
            i++;
        }
        else {
            arr[k] = Right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = Left[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = Right[j];
        j++;
        k++;
    }

    delete[] Left;
    delete[] Right;  
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);  
        merge(arr, l, m, r);
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original array: ";
    printArray(arr, n);
    
    // Uncomment only one of these at a time to test each sorting algorithm
    
    // insertionSort(arr, n);
    // cout << "Array after Insertion Sort: ";
    
    // selectionSort(arr, n);
    // cout << "Array after Selection Sort: ";
    
    // bubbleSort(arr, n);
    // cout << "Array after Bubble Sort: ";
    
    // quickSort(arr, 0, n-1);
    // cout << "Array after Quick Sort: ";
    
    mergeSort(arr, 0, n-1);
    cout << "Array after Merge Sort: ";
    
    printArray(arr, n);
    return 0;
}
