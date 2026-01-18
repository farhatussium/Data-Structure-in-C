#include <stdio.h>
#include <limits.h>
int max(int a,int b){
    int max=(a>b?a:b);
}
int main() {
    int a[]={3,-4,5,4,-1,7,-8};
    int n=sizeof(a)/sizeof(a[0]);
    int MaxSum=INT_MIN,CurSum=0;
    for(int i=0;i<n;i++){
       CurSum+=a[i];
       MaxSum=max(CurSum,MaxSum);
       if(CurSum<0){
           CurSum=0;
       }
    }
    printf("Maximum SubArry Sum:%d",MaxSum);

    return 0;
}