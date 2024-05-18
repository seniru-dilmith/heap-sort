# Heap Sort Algorithm in C++

This repository contains an implementation of the Heap Sort algorithm in C++. The implementation is well-commented to help you understand each step of the algorithm.

## Introduction

Heap Sort is a comparison-based sorting technique based on a binary heap data structure. It is similar to selection sort where we first find the maximum element and place it at the end. We repeat the same process for the remaining elements.

## Algorithms

### MAX_HEAPIFY

The `MAX_HEAPIFY` function maintains the max-heap property for a subtree rooted at index `i`.

```cpp
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
```

### BUILD_MAX_HEAP
The BUILD_MAX_HEAP function builds a max-heap from an unsorted array.

```cpp
void BUILD_MAX_HEAP(std::vector<int>& A) {
    int heap_size = A.size();
    for (int i = (heap_size / 2) - 1; i >= 0; i--) {
        MAX_HEAPIFY(A, heap_size, i);
    }
}
```

### HEAPSORT

The HEAPSORT function sorts an array using the heap sort algorithm.

```cpp
void HEAPSORT(std::vector<int>& A) {
    BUILD_MAX_HEAP(A);
    int heap_size = A.size();
    for (int i = heap_size - 1; i >= 1; i--) {
        exchange(A[0], A[i]);  // Exchange the root (maximum value) with the last element
        heap_size--;  // Reduce the heap size
        MAX_HEAPIFY(A, heap_size, 0);
    }
}
```

## Utility Functions

### LEFT

The LEFT function returns the left child index of a node.

```cpp

int LEFT(int i) {
    return 2 * i + 1;
}
```

### RIGHT

The RIGHT function returns the right child index of a node.

```cpp

int RIGHT(int i) {
    return 2 * i + 2;
}
```

### exchange
The exchange function swaps two elements.

```cpp

void exchange(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
```

### printArray
The printArray function prints the elements of an array.

```cpp

void printArray(const std::vector<int>& A) {
    for (int i = 0; i < A.size(); i++)
        std::cout << A[i] << " ";
    std::cout << std::endl;
}
```
