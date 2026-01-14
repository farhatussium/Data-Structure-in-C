#include <stdio.h>
int main() {
    int a[]={12,2,3,17,7};
    int n=sizeof(a)/sizeof(a[0]);
    for(int i=0;i<n;i++){
        printf("%d\n",a[i]);
    }
    return 0;
}