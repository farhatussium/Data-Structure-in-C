#include <stdio.h>
void InsertionSort(int a[], int n){
    for(int i=1;i<n;i++){
        int cur=a[i];
        int prev=i-1;
        while(prev>=0 && a[prev]>cur){
            a[prev+1]=a[prev];
            prev--;
        }
        a[prev+1]=cur;
    }
}
int main() {
    int a[] = {5, 1, 3, 4, 2};
    int n = sizeof(a) / sizeof(a[0]);

    InsertionSort(a, n);

    printf("Sorted Array: ");
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }

    return 0;
}