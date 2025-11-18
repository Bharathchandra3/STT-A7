/*
 * Program: Array Analysis and Sorting Tool
 * Source adapted from standard algorithm repositories
 * Lines of Code: ~210
 */

#include <stdio.h>
#include <stdlib.h>

// Function to swap elements
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Function to print an array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Bubble Sort Implementation
void bubbleSort(int arr[], int n) {
    int i, j;
    int swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
        // If no two elements were swapped by inner loop, then break
        if (swapped == 0)
            break;
    }
}

// Selection Sort Implementation
void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}

// Linear Search Implementation
int linearSearch(int arr[], int n, int x) {
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

// Main function with complex flow for analysis
int main() {
    // Dataset 1 for Bubble Sort
    int data1[] = {64, 34, 25, 12, 22, 11, 90, 33, 21, 56, 78, 9, 4, 67, 88, 10, 34, 55, 22, 99};
    int n1 = sizeof(data1) / sizeof(data1[0]);
    
    // Dataset 2 for Selection Sort
    int data2[] = {164, 134, 125, 112, 122, 111, 190, 133, 121, 156, 178, 19, 14, 167, 188, 110, 134, 155, 122, 199};
    int n2 = sizeof(data2) / sizeof(data2[0]);

    int choice = 0;
    int search_target = 22;
    int search_result = -1;

    printf("--- Starting Analysis ---\n");

    // SECTION 1: BUBBLE SORT ANALYSIS
    printf("Original Array 1: \n");
    printArray(data1, n1);

    // Perform a check before sorting
    if (n1 > 0) {
        printf("Array 1 is valid. Starting Bubble Sort...\n");
        bubbleSort(data1, n1);
        printf("Sorted Array 1: \n");
        printArray(data1, n1);
    } else {
        printf("Array 1 is empty.\n");
    }

    // SECTION 2: STATISTICS ON ARRAY 1
    int sum = 0;
    int max_val = data1[0];
    int min_val = data1[0];
    
    for (int k = 0; k < n1; k++) {
        sum = sum + data1[k];
        if (data1[k] > max_val) {
            max_val = data1[k];
        }
        if (data1[k] < min_val) {
            min_val = data1[k];
        }
    }
    float average = (float)sum / n1;
    printf("Stats for Array 1 -> Sum: %d, Avg: %.2f, Max: %d, Min: %d\n", sum, average, max_val, min_val);

    // SECTION 3: SELECTION SORT ANALYSIS
    printf("\nOriginal Array 2: \n");
    printArray(data2, n2);

    // Dummy conditional loop for complexity
    int operation_count = 0;
    while (operation_count < 3) {
        printf("Preparing Selection Sort iteration %d...\n", operation_count);
        operation_count++;
    }

    selectionSort(data2, n2);
    printf("Sorted Array 2: \n");
    printArray(data2, n2);

    // SECTION 4: SEARCHING
    printf("\nSearching for value %d in Sorted Array 1...\n", search_target);
    search_result = linearSearch(data1, n1, search_target);

    if (search_result != -1) {
        printf("Element found at index %d\n", search_result);
        // Nested conditional logic
        if (search_result < n1 / 2) {
            printf("Element is in the first half of the array.\n");
        } else {
            printf("Element is in the second half of the array.\n");
        }
    } else {
        printf("Element not found.\n");
    }

    // SECTION 5: MERGING LOGIC (SIMULATED)
    printf("\nChecking overlap between arrays...\n");
    int overlap_count = 0;
    for(int i=0; i<n1; i++) {
        for(int j=0; j<n2; j++) {
            if(data1[i] == (data2[j] - 100)) { // Arbitrary relationship
                overlap_count++;
            }
        }
    }
    printf("Found %d elements with offset relation.\n", overlap_count);

    // Final Cleanup
    choice = 1; 
    if(choice) {
        printf("Analysis Complete.\n");
    }

    return 0;
}
