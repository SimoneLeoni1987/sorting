#ifndef UTILS_H
#define UTILS_H

void swap(int arr[], int x, int y);
void printArray(int arr[], int length);
void space(void);
void merge(int left[], int leftSize, int right[], int rightSize, int result[]);
void mergeInPlace(int arr[], int start, int pivot, int end);

#endif