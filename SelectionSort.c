#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SelectionSort(int a[], int n){
    for(int i=0;i<n-1; i++){
        int SmIn=i;
        for(int j=i+1;j<n;j++){
            if(a[j] < a[SmIn]){
                SmIn=j;
            }
        }
        swap(&a[i],&a[SmIn]);
    }
}

int main() {
    int a[] = {5, 1, 3, 4, 2};
    int n = sizeof(a) / sizeof(a[0]);

    SelectionSort(a, n);

    printf("Sorted Array: ");
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}
