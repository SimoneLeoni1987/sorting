#include <stdio.h>
#include "utils.h"

void space(void) {
    printf("\n");
}

void swap(int arr[], int x, int y) {
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

void printArray(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    space();
}

void cleanArray(int arr[], int length) {
     for (int i = 0; i < length; i++) {
        arr[i] = 0;
    }
}

void mergeInPlace(int arr[], int start, int pivot, int end) {
    int i = start; // for the "first" half
    int j = pivot + 1; // for the "second" half
    int k = 0; // For the array

    int first_half_end = (pivot + 1);
    int second_half_end = (end + 1);

    // temp result array -> copy
    int dim = (end - start) + 1;
    int temp[dim];
    int arr_index = start;
    for (int z = 0; z < dim; z++)
        temp[z] = arr[arr_index++];


    while (i < first_half_end && j < second_half_end) {
        if (arr[i] < arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    // Fill the rest!
    if (i < first_half_end) {
        while (i < first_half_end) {
            temp[k] = arr[i];
            k++;
            i++;
        }
    }

    if (j < second_half_end) {
        while (j < second_half_end) {
            temp[k] = arr[j];
            k++;
            j++;
        }
    }

    // Copy back to arr!
    for (int z = 0; z < dim; z++) 
        arr[start+z] = temp[z];
    
}

void merge(int left[], int leftSize, int right[], int rightSize, int result[]) {
    int i = 0; // Right
    int j = 0; // Left
    int k = 0; // For the result

    while (i < rightSize && j < leftSize) {
        if (right[i] >= left[j]) {
            result[k] = left[j];
            j++;
        } else {
            result[k] = right[i];
            i++;
        }

        k++;
    }

    // Fill the rest
    if (i < rightSize) {
        while (i < rightSize) {
            result[k] = right[i];
            k++;
            i++;
        }
    }

    if (j < leftSize) {
        while (j < leftSize) {
            result[k] = left[j];
            k++;
            j++;
        }
    }
}
