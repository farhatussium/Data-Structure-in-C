#include<stdio.h>
int binarySearch(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid; // Target found
        } else if (arr[mid] < target) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }
    return -1; // Target not found
}
int main(){
    int arr1[] = {2, 3, 4, 10, 40};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int target1 = 10;
    int result1 = binarySearch(arr1, n1, target1);
    int arr2[] = {1, 5, 8, 12, 20, 25};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int target2 = 12;
    int result2 = binarySearch(arr2, n2, target2);
    printf("Element %d is present at index %d in arr1\n", target1, result1);
    printf("Element %d is present at index %d in arr2\n", target2, result2);

    return 0;
}