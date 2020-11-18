#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 2;  // Declare an integer i.
    int *ip;  // Declare a pointer to an integer ip.
    
    ip = &i;  // Store the address of i in ip.
    
    printf("%d\n", *ip);  // Dereference ip to get the value it points to (2).
    
    int *np = NULL;
    // Dereferencing np here would result in a Segmentation Fault.
    // printf("%d\n", *np);
    
    // Dynamically allocate memory for np on the heap.
    np = (int *) malloc(sizeof(int));
    
    // Free the memory.
    free(np);
    
    return 0;
}