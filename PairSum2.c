#include <stdio.h>

int main()
{
    int arr[] = {1, 4, 6, 8, 3, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;
    /* Sort array (simple bubble sort) */
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    int left = 0, right = n - 1;
    printf("Pairs with sum %d:\n", target);
    while(left < right){
        int sum = arr[left] + arr[right];

        if(sum == target){
            printf("(%d, %d)\n", arr[left], arr[right]);
            left++;
            right--;
        }
        else if(sum < target){
            left++;
        }
        else{
            right--;
        }
    }

    return 0;
}
