#include<stdio.h>
int main(){
    int a[]={1,2,3,4,5};
    int b[]={4,5,6,7,8};
    int sizeA=5, sizeB=5;
    printf("Intersection of two arrays:\n");
    for(int i=0;i<sizeA;i++){
        for(int j=0;j<sizeB;j++){
            if(a[i]==b[j]){
                printf("%d ",a[i]);
                break;
            }
        }
    }
  return 0;  
}