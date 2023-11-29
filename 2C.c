#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Function to swap two integers
void swap(int* a, int* b) {
int temp = *a;
*a = *b;
*b = temp;
}
// Bubble Sort
void bubbleSort(int arr[], int n) {
int i, j;
for (i = 0; i < n - 1; i++) {
for (j = 0; j < n - i - 1; j++) {
if (arr[j] > arr[j + 1]) {
swap(&arr[j], &arr[j + 1]);
}
}
}
}
// Selection Sort
void selectionSort(int arr[], int n) {
int i, j, min_idx;
for (i = 0; i < n - 1; i++) {
min_idx = i;

for (j = i + 1; j < n; j++) {
if (arr[j] < arr[min_idx]) {
min_idx = j;
}
}
if (min_idx != i) {
swap(&arr[i], &arr[min_idx]);
}
}
}
// Insertion Sort
void insertionSort(int arr[], int n) {
int i, key, j;
for (i = 1; i < n; i++) {   
key = arr[i];
j = i - 1;
while (j >= 0 && arr[j] > key) {
arr[j + 1] = arr[j];
j = j - 1;
}
arr[j + 1] = key;
}
}
// Function to generate random integers and save them in arr[]
void generateRandomArray(int arr[], int n) {
int i;
for (i = 0; i < n; i++) {
arr[i] = rand();
}
}
int main() {
int n = 10000;
int arr[n], arr1[n], arr2[n], arr3[n];
double time_taken;
// Generate random data and copy to different arrays
generateRandomArray(arr, n);
for (int i = 0; i < n; i++) {
arr1[i] = arr[i];
arr2[i] = arr[i];
arr3[i] = arr[i];

}
// Measure the execution time for Bubble Sort
clock_t start_bubble = clock();
bubbleSort(arr, n);
clock_t end_bubble = clock();
time_taken = ((double)(end_bubble - start_bubble)) / CLOCKS_PER_SEC;
printf("Time taken for Bubble Sort: %f seconds\n", time_taken);
// Measure the execution time for Selection Sort
clock_t start_selection = clock();
selectionSort(arr1, n);
clock_t end_selection = clock();
time_taken = ((double)(end_selection - start_selection)) / CLOCKS_PER_SEC;
printf("Time taken for Selection Sort: %f seconds\n", time_taken);
// Measure the execution time for Insertion Sort
clock_t start_insertion = clock();
insertionSort(arr2, n);
clock_t end_insertion = clock();
time_taken = ((double)(end_insertion - start_insertion)) / CLOCKS_PER_SEC;
printf("Time taken for Insertion Sort: %f seconds\n", time_taken);
return 0;
}