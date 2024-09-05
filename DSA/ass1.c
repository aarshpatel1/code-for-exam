#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number of integers you want to enter: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("Integer %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("You entered:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Integer %d: %d\n", i + 1, arr[i]);
    }
    return 0;
}