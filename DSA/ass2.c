#include <stdio.h>

int main() {
    char arr[100]; // Create a character array to store the input
    int i;

    printf("Enter a string: ");
    fgets(arr, sizeof(arr), stdin); // Read the input from the user

    printf("Characters entered:\n");
    for (i = 0; arr[i] != '\0' && arr[i] != '\n'; i++) {
        printf("%c ", arr[i]); // Print each character in the array
    }
    printf("\n");

    return 0;
}