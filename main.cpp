#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>  // For using numeric_limits

// Function prototypes
void MAX_HEAPIFY(std::vector<int>& A, int heap_size, int i);
void BUILD_MAX_HEAP(std::vector<int>& A);
void HEAPSORT(std::vector<int>& A);
int HEAPMAXIMUM(const std::vector<int>& A);
int HEAPEXTRACTMAX(std::vector<int>& A);
void HEAPINCREASEKEY(std::vector<int>& A, int i, int key);
void MAX_HEAPINSERT(std::vector<int>& A, int key);

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

// Function to return the maximum element of the heap
int HEAPMAXIMUM(const std::vector<int>& A) {
    return A[0];
}

// Function to extract the maximum element from the heap
int HEAPEXTRACTMAX(std::vector<int>& A) {
    if (A.empty()) {
        std::cerr << "Heap underflow" << std::endl;
        return std::numeric_limits<int>::min();  // Return negative infinity
    }
    int max = A[0];
    A[0] = A.back();
    A.pop_back();
    MAX_HEAPIFY(A, A.size(), 0);
    return max;
}

// Function to increase the key of a node in the heap
void HEAPINCREASEKEY(std::vector<int>& A, int i, int key) {
    if (key < A[i]) {
        std::cerr << "New key is smaller than the current key" << std::endl;
        return;
    }
    A[i] = key;
    while (i > 0 && A[i] > A[(i - 1) / 2]) {
        exchange(A[i], A[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to insert a new key into the heap
void MAX_HEAPINSERT(std::vector<int>& A, int key) {
    A.push_back(std::numeric_limits<int>::min());  // Insert negative infinity as a placeholder
    HEAPINCREASEKEY(A, A.size() - 1, key);
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

    BUILD_MAX_HEAP(A);
    std::cout << "Max heap: ";
    printArray(A);

    std::cout << "Maximum element in the heap: " << HEAPMAXIMUM(A) << std::endl;

    std::cout << "Extracted maximum element: " << HEAPEXTRACTMAX(A) << std::endl;
    std::cout << "Heap after extraction: ";
    printArray(A);

    std::cout << "Increase key at index 2 to 20" << std::endl;
    HEAPINCREASEKEY(A, 2, 20);
    std::cout << "Heap after increasing key: ";
    printArray(A);

    std::cout << "Inserting new element 15 into the heap" << std::endl;
    MAX_HEAPINSERT(A, 15);
    std::cout << "Heap after insertion: ";
    printArray(A);

    return 0;
}
