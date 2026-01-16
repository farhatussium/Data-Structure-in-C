#include <stdio.h>
int RSBS(int a[],int tar,int n){
    int st=0,end=n-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(tar==a[mid]){return mid;}
        if(a[st]<=a[mid]){        //left Sorted
            if(a[st]<=tar && tar<=a[mid]){
                end=mid-1;
            }
            else{
                st=mid+1;
            }
        }else{        //Right Sorted
            if(a[mid]<=tar && tar<=a[end]){
                st=mid+1;
            }
            else{
                end=mid-1;
            }
        }
    }
    return -1;
}

int main() {
   int target=7;
   int a1[]={3,4,5,6,7,0,1,2};
   int n1=sizeof(a1)/sizeof(a1[0]);
   int a2[]={6,7,0,1,2,3,4,5};
   int n2=sizeof(a2)/sizeof(a2[0]);
   int result1=RSBS(a1,target,n1);
   int result2=RSBS(a2,target,n2);
   printf("%d in 1st ARRY in %d index\n",target,result1);
   printf("%d in 2nd ARRY in %d index\n",target,result2);

    return 0;
}