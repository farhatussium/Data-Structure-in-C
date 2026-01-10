#include <stdio.h>
int search(int arr[],int size,int target){
    for(int i=0;i<size;i++){
        if(arr[i]==target){
            return i;
        }
    }
    return -1;
}

int main(){ 
    int arr[]={1,2,3,4,5,6};
    int size=6;
    int target=4;
    int result=search(arr,size,target);
    printf("Element found at index: %d\n",result);
    return 0;
}


