#include<stdio.h>
int main(){
int n,pos,val;
int arr[n];
printf("Enter the number of elements in the array: ");
scanf("%d",&n);
printf("Enter the elements of the array:\n");
for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
}
printf("Enter the position to insert the new element (0 to %d): ", n);
scanf("%d",&pos);
if(pos<0 || pos>n){
    printf("Invalid position!\n");
    return 1;
}
printf("Enter the value to insert: ");
scanf("%d",&val);
for(int i=n;i>pos;i--){
    arr[i]=arr[i-1];
}
arr[pos]=val;
printf("Element inserted successfully!\n");
printf("Updated array elements:\n");
for(int i=0;i<n+1;i++){
    printf("%d ",arr[i]);
}
return 0;
}