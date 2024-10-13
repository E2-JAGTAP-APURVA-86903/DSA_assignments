#include<stdio.h>
#define SIZE 9

int comparisons; // Global variable to track comparisons
int rec_linear_search(int arr[SIZE], int key, int index);
int rec_binary_search(int arr[SIZE], int key, int left, int right);
void Print_Array(int arr[SIZE]);

int main() {
    int arr[SIZE] = {11, 22, 33, 44, 55, 66, 77, 88, 99};
    int key;

    Print_Array(arr);

    printf("Enter the Key to Search :");
    scanf("%d", &key); // 66

    
    comparisons = 0;
    int index = rec_linear_search(arr, key, 0);

    if (index == -1)
        printf("Key not found!\n");
    else
        printf("Key found at index = %d\n", index);

    printf("Comparisons in linear search = %d\n", comparisons);

    printf("\nRecursive Binary Search:\n");

    
    comparisons = 0;
    int res = rec_binary_search(arr, key, 0, SIZE - 1);

    if (res == -1)
        printf("Key not found!\n");
    else
        printf("Key found at index = %d\n", res);

    printf("Comparisons in binary search = %d\n", comparisons);

    return 0;
}

// Recursive linear search
int rec_linear_search(int arr[SIZE], int key, int index) {
    comparisons++; // Increment comparisons for each function call

    if (index >= SIZE) 
        return -1;

    if (arr[index] == key) 
        return index;

    return rec_linear_search(arr, key, index + 1); // Recursive call to next element
}

// Recursive binary search
int rec_binary_search(int arr[SIZE], int key, int left, int right) {
    comparisons++; 

    if (left > right) 
        return -1;

    int mid = (left + right) / 2;

    if (arr[mid] == key) 
        return mid;

    if (key < arr[mid])
        return rec_binary_search(arr, key, left, mid - 1); // Recursive call to left half
    else
        return rec_binary_search(arr, key, mid + 1, right); // Recursive call to right half
}


void Print_Array(int arr[SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        printf("%-4d", arr[i]);
    }
    printf("\n");
}