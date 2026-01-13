#include<stdio.h>
int main(){
    int n,pos;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the position to delete the element (0 to %d): ", n-1);
    scanf("%d",&pos);
    if(pos<0 || pos>=n){
        printf("Invalid position!\n");
        return 1;
    }
    for(int i=pos;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    printf("Element deleted successfully!\n");
    printf("Updated array elements:\n");
    for(int i=0;i<n-1;i++){
        printf("%d ",arr[i]);
    }
return 0;
}