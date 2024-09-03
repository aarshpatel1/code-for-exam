#include <stdio.h>
int main()
{
    char arr[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd'};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Character array elements:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%c ", arr[i]);
    }
    printf("\n");
    return 0;
}