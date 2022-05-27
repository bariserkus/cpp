#include <stdio.h>

/**
 * Function to return an array using pointers.
 * @return 	Pointer to array
 */
int * getArray()
{
    static int num[] = {1, 2, 3, 4, 5};
    int i;

    printf("Array inside function: ");
    // Print value of each array element
    for (i = 0; i < 5; ++i)
    {
        printf("%d\n", num[i]);
    }

    return num;
}

int main()
{
    int i;

    // Pointer to store array
    int * num;
    int * test;

    *test = 5;

    // Call getArray function to get pointer to array
    num = getArray();

    printf("Array outside function: \n");
    // Print value of each array element
    for (i = 0; i < 5; ++i)
    {
        printf("%d\n", num[i]);
    }

    printf("%d\n", test[0]);



    return 0;
}
