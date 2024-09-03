#include <stdio.h>
int main()
{
    int size;
    int sum = 0;
    printf("Enter the number of integers: ");
    scanf("%d", &size);
    if (size <= 0)
    {
        printf("The number of integers must be positive.\n");
        return 1;
    }
    int arr[size];
    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++)
    {
        printf("Integer %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    printf("The sum of the entered integers is: %d\n", sum);
    return 0;
}