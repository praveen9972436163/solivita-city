#include <iostream>
#include <vector>
using namespace std;

// Function to build the max-heap by heapifying downwards
void heapify(vector<int>& H, int n, int i) {
    int k = i;          // Current node
    int v = H[k];       // Value at current node
    bool heap = false;

    while (!heap && 2 * k <= n) {  // While there is at least a left child
        int j = 2 * k;             // Left child index
        if (j < n && H[j] < H[j + 1])  // If right child exists and is greater
            j++;
        
        if (v >= H[j])             // If current value is greater than or equal to the largest child
            heap = true;
        else {
            H[k] = H[j];           // Move the largest child up
            k = j;                 // Move to the next level
        }
    }
    H[k] = v;                      // Place the original value in the correct position
}

// Function to perform heap sort
void heapSort(vector<int>& H) {
    int n = H.size() - 1;          // Assuming the array is 1-indexed

    // Step 1: Build a max heap
    for (int i = n / 2; i >= 1; i--) {
        heapify(H, n, i);
    }

    // Step 2: Extract elements from the heap
    for (int i = n; i > 1; i--) {
        swap(H[1], H[i]);          // Swap the root (largest) with the last element
        heapify(H, i - 1, 1);      // Heapify the reduced heap
    }
}

int main() {
    // 1-indexed array (dummy element at index 0)
    vector<int> H = {0, 4, 10, 3, 5, 1}; 

    cout << "Original array: ";
    for (int i = 1; i < H.size(); i++)
        cout << H[i] << " ";
    cout << endl;

    heapSort(H);

    cout << "Sorted array: ";
    for (int i = 1; i < H.size(); i++)
        cout << H[i] << " ";
    cout << endl;

    return 0;
}
