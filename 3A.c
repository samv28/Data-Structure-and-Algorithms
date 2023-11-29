#include <stdio.h>

// Function to merge two sorted subarrays
void merge(int arr[], int left, int middle, int right, int *comparisons) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int leftArray[n1], rightArray[n2];

    for (int i = 0; i < n1; i++)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArray[j] = arr[middle + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        (*comparisons)++;
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

// Optimized Merge Sort
void mergeSort(int arr[], int left, int right, int *comparisons) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle, comparisons);
        mergeSort(arr, middle + 1, right, comparisons);

        if (arr[middle] > arr[middle + 1]) {
            merge(arr, left, middle, right, comparisons);
        }
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[100];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int comparisons = 0;
    
    printf("Array before sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    mergeSort(arr, 0, n - 1, &comparisons);
    
    printf("\nArray after sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nTotal comparisons: %d\n", comparisons);

    return 0;
}
