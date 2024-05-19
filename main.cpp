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
    // Get the indices of the left and right children of the node at index i
    int l = LEFT(i);
    int r = RIGHT(i);
    int largest;

    // Check if the left child is larger than the current node
    if (l < heap_size && A[l] > A[i])
        largest = l;
    else
        largest = i;

    // Check if the right child is larger than the largest so far
    if (r < heap_size && A[r] > A[largest])
        largest = r;

    // If the largest element is not the current node, swap and recurse
    if (largest != i) {
        exchange(A[i], A[largest]);
        MAX_HEAPIFY(A, heap_size, largest);
    }
}

// Function to build a max-heap from an unsorted array
void BUILD_MAX_HEAP(std::vector<int>& A) {
    int heap_size = A.size();
    // Start from the last non-leaf node and heapify each node
    for (int i = (heap_size / 2) - 1; i >= 0; i--) {
        MAX_HEAPIFY(A, heap_size, i);
    }
}

// Function to perform heap sort
void HEAPSORT(std::vector<int>& A) {
    // Build a max-heap from the input array
    BUILD_MAX_HEAP(A);
    int heap_size = A.size();
    // Extract elements from the heap one by one
    for (int i = heap_size - 1; i >= 1; i--) {
        exchange(A[0], A[i]);  // Move the current root to the end
        heap_size--;  // Reduce the heap size
        MAX_HEAPIFY(A, heap_size, 0);  // Heapify the reduced heap
    }
}

// Function to return the maximum element of the heap
int HEAPMAXIMUM(const std::vector<int>& A) {
    return A[0];  // The maximum element is at the root
}

// Function to extract the maximum element from the heap
int HEAPEXTRACTMAX(std::vector<int>& A) {
    if (A.empty()) {
        std::cerr << "Heap underflow" << std::endl;
        return std::numeric_limits<int>::min();  // Return negative infinity
    }
    int max = A[0];  // The maximum element is at the root
    A[0] = A.back();  // Move the last element to the root
    A.pop_back();  // Remove the last element
    MAX_HEAPIFY(A, A.size(), 0);  // Heapify the root
    return max;  // Return the maximum element
}

// Function to increase the key of a node in the heap
void HEAPINCREASEKEY(std::vector<int>& A, int i, int key) {
    if (key < A[i]) {
        std::cerr << "New key is smaller than the current key" << std::endl;
        return;
    }
    A[i] = key;  // Set the new key
    // Restore the max-heap property by moving the node up the tree
    while (i > 0 && A[i] > A[(i - 1) / 2]) {
        exchange(A[i], A[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to insert a new key into the heap
void MAX_HEAPINSERT(std::vector<int>& A, int key) {
    A.push_back(std::numeric_limits<int>::min());  // Insert negative infinity as a placeholder
    HEAPINCREASEKEY(A, A.size() - 1, key);  // Increase the key to the desired value
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

    // Build a max-heap from the original array
    BUILD_MAX_HEAP(A);
    std::cout << "Max heap: ";
    printArray(A);

    // Display the maximum element in the heap
    std::cout << "Maximum element in the heap: " << HEAPMAXIMUM(A) << std::endl;

    // Extract the maximum element from the heap
    std::cout << "Extracted maximum element: " << HEAPEXTRACTMAX(A) << std::endl;
    std::cout << "Heap after extraction: ";
    printArray(A);

    // Increase the key at index 2 to 20
    std::cout << "Increase key at index 2 to 20" << std::endl;
    HEAPINCREASEKEY(A, 2, 20);
    std::cout << "Heap after increasing key: ";
    printArray(A);

    // Insert a new element 15 into the heap
    std::cout << "Inserting new element 15 into the heap" << std::endl;
    MAX_HEAPINSERT(A, 15);
    std::cout << "Heap after insertion: ";
    printArray(A);

    return 0;
}
