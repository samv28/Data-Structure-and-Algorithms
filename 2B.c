#include <stdio.h>

void bubbleSortDescending(int arr[], int n) {
    int i, j, temp;
    int sorted = 0; // Flag to track if the array is already sorted
    
    for (i = 0; i < n - 1; i++) {
        sorted = 1; // Assume the array is sorted
        
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                sorted = 0; // If a swap is performed, the array is not sorted yet
            }
        }
        
        if (sorted) {
            // If the array is already sorted, terminate the sorting process early
            break;
        }
    }
}

int main() {
    int arr[100]; // Array to store the elements
    int size, i;
    
    // Prompt the user to enter the size of the array
    printf("Enter the size of the array (maximum size: 100): ");
    scanf("%d", &size);
    
    // Check for valid array size
    if (size <= 0 || size > 100) {
        printf("Invalid array size. Please enter a size between 1 and 100.\n");
        return 1; // Return 1 to indicate an error
    }
    
    // Prompt the user to enter the elements of the array
    printf("Enter the elements of the array:\n");
    for (i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    // Call the Bubble Sort Descending function to sort the array
    bubbleSortDescending(arr, size);
    
    // Display the sorted array
    printf("Sorted array in descending order: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0; // Return 0 to indicate successful program execution
}
