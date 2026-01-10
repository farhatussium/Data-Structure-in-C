#include<stdio.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int main(){
    int arr[]={1,2,4,6,8,9};
    int size=6;
    int st=0,sp=size-1;
    while(st<sp){
        swap(&arr[st],&arr[sp]);
        st++;
        sp--;
    }
    printf("Reversed array: ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}