#include<stdio.h>

int main()
{
    int arr[] = {1,2,3,1,2,3,4};
    int size = 7;
    int found = 0;

    printf("Unique elements are:\n");

    for(int i = 0; i < size; i++)
    {
        int count = 0;

        for(int j = 0; j < size; j++)
        {
            if(arr[i] == arr[j])
            {
                count++;
            }
        }

        if(count == 1)
        {
            printf("%d\n", arr[i]);
            found = 1;
        }
    }

    if(!found)
    {
        printf("No unique elements found.\n");
    }

    return 0;
}

