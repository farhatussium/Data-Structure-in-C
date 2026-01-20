#include <stdio.h>

int main()
{
    int arr[] = {2,2,1,2,3,2,2};
    int n = sizeof(arr) / sizeof(arr[0]);

    for(int i = 0; i < n; i++)
    {
        int count = 0;

        for(int j = 0; j < n; j++)
        {
            if(arr[i] == arr[j])
                count++;
        }

        if(count > n / 2)
        {
            printf("Majority Element: %d\n", arr[i]);
            return 0;
        }
    }

    printf("No Majority Element\n");
    return 0;
}
