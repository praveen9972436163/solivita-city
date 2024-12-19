#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& H, int n, int i) {
    int k = i;        
    int v = H[k];      
    bool heap = false;

    while (!heap && 2 * k <= n) { 
        int j = 2 * k;            
        if (j < n && H[j] < H[j + 1])  
            j++;
        
        if (v >= H[j])           
            heap = true;
        else {
            H[k] = H[j];           
            k = j;                
        }
    }
    H[k] = v;                      
}


void heapSort(vector<int>& H) {
    int n = H.size() - 1;          

    
    for (int i = n / 2; i >= 1; i--) {
        heapify(H, n, i);
    }

  
    for (int i = n; i > 1; i--) {
        swap(H[1], H[i]);        
        heapify(H, i - 1, 1);   
    }
}

int main() {
  
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
