#include "sorting.h"
#include "utils.h"

// The greatest will be pushed every iteration towards
// the end of the array -> O(n^2) because of the double cycle
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (n - i); j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr, j, j+1);
            }
        }
    }
}

// Go further until we find a smaller element.. we are going
// then to push it back in the right position! -> O(n^2)
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j-1 >= 0 && arr[j] < arr[j-1] ; j--) {
           swap(arr, j, j-1);
        }
    }
}

// We have the first part of the array already sorted and we need to swap
// the next smallest element in the second part of the array -> O(n^2)
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int smallestIndex = i;
        
        for (int j = i; j < n ; j++) {
            if (arr[smallestIndex] > arr[j]) {
                smallestIndex = j;
            }
        }
        swap(arr, i, smallestIndex);
    }
}

// Divide and conquer. Split the array in halves and then reconstruct it with merging the two parts 
// into one
void mergeSortRecursive(int arr[], int result[], int start, int end) {
    
    // Base case
    if (start >= end) {
        result[0] = arr[start];
        return;
    } 

    // Find pivot
    int pivot = ((end - start) / 2) + start;
    int leftSize = pivot - start + 1;
    int rightSize = end - pivot;

    int left[leftSize];
    int right[rightSize]; 

    mergeSortRecursive(arr, left, start, pivot);
    mergeSortRecursive(arr, right, pivot + 1, end);

    merge(left, leftSize, right, rightSize, result);
}

void mergeSort(int arr[], int n) {
    int result[n];
    mergeSortRecursive(arr, result, 0, n - 1);
}

void mergeSortNoResultArrayRecursive(int arr[], int start, int end) {
    if (start < end) {
        // Find pivot
        int pivot = ((end - start) / 2) + start;

        mergeSortNoResultArrayRecursive(arr, start, pivot);
        mergeSortNoResultArrayRecursive(arr, pivot + 1, end);

        mergeInPlace(arr, start, pivot, end);
    }
}

void mergeSortNoResultArray(int arr[], int n) {
    mergeSortNoResultArrayRecursive(arr, 0, n-1);
}