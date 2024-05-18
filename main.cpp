#include <iostream>
#include <vector>
#include <algorithm>

// Function prototypes
void MAX_HEAPIFY(std::vector<int>& A, int heap_size, int i);
void BUILD_MAX_HEAP(std::vector<int>& A);
void HEAPSORT(std::vector<int>& A);

// Function to get the left child index
int LEFT(int i) {
    return 2 * i + 1;
}

// Function to get the right child index
int RIGHT(int i) {
    return 2 * i + 2;
}

// Function to swap two elements
void exchange(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function to maintain the max-heap property
void MAX_HEAPIFY(std::vector<int>& A, int heap_size, int i) {
    int l = LEFT(i);
    int r = RIGHT(i);
    int largest;

    if (l < heap_size && A[l] > A[i])
        largest = l;
    else
        largest = i;

    if (r < heap_size && A[r] > A[largest])
        largest = r;

    if (largest != i) {
        exchange(A[i], A[largest]);
        MAX_HEAPIFY(A, heap_size, largest);
    }
}

// Function to build a max-heap from an unsorted array
void BUILD_MAX_HEAP(std::vector<int>& A) {
    int heap_size = A.size();
    for (int i = (heap_size / 2) - 1; i >= 0; i--) {
        MAX_HEAPIFY(A, heap_size, i);
    }
}

// Function to perform heap sort
void HEAPSORT(std::vector<int>& A) {
    BUILD_MAX_HEAP(A);
    int heap_size = A.size();
    for (int i = heap_size - 1; i >= 1; i--) {
        exchange(A[0], A[i]);  // Exchange the root (maximum value) with the last element
        heap_size--;  // Reduce the heap size
        MAX_HEAPIFY(A, heap_size, 0);
    }
}

// Utility function to print the array
void printArray(const std::vector<int>& A) {
    for (int i = 0; i < A.size(); i++)
        std::cout << A[i] << " ";
    std::cout << std::endl;
}

int main() {
    std::vector<int> A = {12, 11, 13, 5, 6, 7, 4, 6};

    std::cout << "Original array: ";
    printArray(A);

    HEAPSORT(A);

    std::cout << "Sorted array: ";
    printArray(A);

    return 0;
}
