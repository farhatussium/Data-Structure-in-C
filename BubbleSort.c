#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int a[], int n){
    for(int i = 0; i < n - 1; i++){
        int swapped = 0;
        for(int j = 0; j < n - i - 1; j++){
            if(a[j] > a[j + 1]){
                swap(&a[j], &a[j + 1]);
                swapped = 1;
            }
        }
        if(!swapped){
            return; // Array is already sorted
        }
    }
}

int main() {
    int a[] = {5, 1, 3, 4, 2};
    int n = sizeof(a) / sizeof(a[0]);

    BubbleSort(a, n);

    printf("Sorted Array: ");
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}
