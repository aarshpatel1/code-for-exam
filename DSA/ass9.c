#include <stdio.h>
#define MAX 100

int main()
{
    int n, arr[MAX];
    long long product = 1;
    printf("Enter the number of elements in the array (max %d): ", MAX);
    scanf("%d", &n);
    if (n <= 0 || n > MAX)
    {
        printf("Invalid number of elements %d\n", MAX);
        return 1;
    }
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
        product *= arr[i];
    }

    printf("The product of the array elements is: %lld\n", product);
    return 0;
}