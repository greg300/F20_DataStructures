#include <stdio.h>
#include <stdlib.h>

int seq_search(int *arr, int size, int target)
{
    int i;
    for (i = 0; i <= size; i++)
    {
        if (target == arr[i])
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    // Create and allocate an array of 10 integers.
    int size = 10;
    int *arr = malloc(size * sizeof(int));
    
    // Initialize some values.
    arr[0] = 13;
    arr[1] = 6;
    
    // This should output 1, the index at which 6 is found.
    printf("%d\n", seq_search(arr, size, 6));

    return 0;
}