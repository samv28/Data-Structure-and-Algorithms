#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Quick Sort implementation
void quickSort(int arr[], int left, int right);
int partition(int arr[], int left, int right);

// Merge Sort implementation
void merge(int arr[], int left, int middle, int right);
void mergeSort(int arr[], int left, int right);

// Bubble Sort implementation
void bubbleSort(int arr[], int n);

// Selection Sort implementation
void selectionSort(int arr[], int n);

// Insertion Sort implementation
void insertionSort(int arr[], int n);

int main() {
    srand(time(NULL)); // Seed the random number generator

    int n = 10000;
    int arr[n], arr1[n], arr2[n], arr3[n], arr4[n], arr5[n];

    // Generate random data
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000; // Random integers between 0 and 99999
        arr1[i] = arr[i];
        arr2[i] = arr[i];
        arr3[i] = arr[i];
        arr4[i] = arr[i];
        arr5[i] = arr[i];
    }

    clock_t start, end;
    double time_taken;

    // Quick Sort
    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Quick Sort: %f seconds\n", time_taken);

    // Merge Sort (Code A)
    start = clock();
    mergeSort(arr1, 0, n - 1);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Merge Sort (Code A): %f seconds\n", time_taken);

    // Bubble Sort
    start = clock();
    bubbleSort(arr2, n);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Bubble Sort: %f seconds\n", time_taken);

    // Selection Sort
    start = clock();
    selectionSort(arr3, n);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Selection Sort: %f seconds\n", time_taken);

    // Insertion Sort
    start = clock();
    insertionSort(arr4, n);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Insertion Sort: %f seconds\n", time_taken);

    return 0;
}

// Quick Sort
void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int pivotIndex = partition(arr, left, right);
        quickSort(arr, left, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, right);
    }
}

int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[right];
    arr[right] = temp;

    return i + 1;
}

// Merge Sort
void merge(int arr[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int leftArray[n1], rightArray[n2];

    for (int i = 0; i < n1; i++)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArray[j] = arr[middle + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        if (arr[middle] > arr[middle + 1]) {
            merge(arr, left, middle, right);
        }
    }
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
