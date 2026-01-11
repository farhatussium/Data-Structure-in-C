#include<stdio.h>
#include<limits.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int arr[] = {3, 5, 8, 1, 2, 7};
    int size = 6;
    int min = INT_MAX, max = INT_MIN;
    int minIndex = 0, maxIndex = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] < min){
            min = arr[i];
            minIndex = i;
        }
        if(arr[i] > max){
            max = arr[i];
            maxIndex = i;
        }
    }
    swap(&arr[minIndex], &arr[maxIndex]);
    printf("Array after swapping min and max:\n");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
