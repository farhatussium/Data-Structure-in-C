#include <stdio.h>
#include <limits.h>
int max(int a,int b){
    int max=(a>b?a:b);
}
int main() {
    int a[]={3,-4,5,4,-1,7,-8};
    int n=sizeof(a)/sizeof(a[0]);
    int MaxSum=INT_MIN;
    for(int st=0;st<n;st++){
        int CurSum=0;
        for(int end=st;end<n;end++){
            CurSum+=a[end];
            MaxSum=max(CurSum,MaxSum);
        }
    }
    printf("Maximum SubArry Sum:%d",MaxSum);

    return 0;
}