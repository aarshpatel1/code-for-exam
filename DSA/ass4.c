#include <stdio.h>

int main() {
    int a[] = {10, 20, 30, 40, 50}; // An array of integers
    int i = 2;

    // Accessing the array elements using both a[i] and i[a]
    printf("a[i] = %d\n", a[i]); // Expected output: 30
    printf("i[a] = %d\n", i[a]); // Expected output: 30

    return 0;
}

