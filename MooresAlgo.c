#include <stdio.h>

int main()
{
    int arr[] = {2,2,1,2,3,2,2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int candidate = arr[0];
    int count = 1;
    // Step 1: Find candidate
    for(int i = 1; i < n; i++)
    {
        if(arr[i] == candidate)
            count++;
        else
            count--;

        if(count == 0)
        {
            candidate = arr[i];
            count = 1;
        }
    }
    // Step 2: Verify candidate
    count = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == candidate)
            count++;
    }

    if(count > n / 2)
        printf("Majority Element: %d\n", candidate);
    else
        printf("No Majority Element\n");

    return 0;
}
