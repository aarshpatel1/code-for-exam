#include <stdio.h>

int main()
{
    int arr1[5] = {1, 2, 3, 4, 5};
    char arr2[4] = {'a', 'b', 'c', '\0'};
    printf("Integer array elements:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");
    printf("Character array elements:\n");
    for (int i = 0; i < 4; i++)
    {
        printf("%c ", arr2[i]);
    }
    printf("\n");
    return 0;
}