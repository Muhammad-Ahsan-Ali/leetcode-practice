#include <iostream>
#include <vector>
#include <cstdlib> // For rand()
using namespace std;

int partition(int low, int high, int pivot_index, vector<int>& arr) {
    int pivot = arr[pivot_index];
    swap(arr[pivot_index], arr[high]); // Move pivot to end

    int store_index = low;
    for (int i = low; i < high; i++) {
        if (arr[i] < pivot) {
            swap(arr[i], arr[store_index]);
            store_index++;
        }
    }

    swap(arr[store_index], arr[high]); // Move pivot to its final place
    return store_index; // Return pivot's new index
}

void quickSort(int low, int high, vector<int>& arr) {
    if (low < high) {
        int pivot_index = rand() % (high - low + 1) + low;
        int new_pivot = partition(low, high, pivot_index, arr);

        quickSort(low, new_pivot - 1, arr);  // Sort left part
        quickSort(new_pivot + 1, high, arr); // Sort right part
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();

    quickSort(0, n - 1, arr);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
