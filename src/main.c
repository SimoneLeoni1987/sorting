#include <stdio.h>
#include "utils.h"
#include "sorting.h"

int main() {
    int length = 10;
    int arr[] = {9, 3, 4, 2, 5, 10, 8, 1, 6, 7};

    printf("Starting array = ");
    printArray(arr, length);

    // bubbleSort(arr, length);
    // insertionSort(arr, length);
    // mergeSort(arr, length);
    // mergeSortNoResultArray(arr, length);
    selectionSort(arr, length);

    printf("Sorted = ");
    printArray(arr, length);
}

