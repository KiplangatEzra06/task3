/* Question 4(d): Generate N terms of the Fibonacci series using recursion
 * Series: 0, 1, 1, 2, 3, 5, 8, ...
 */
#include <stdio.h>

int fibonacci(int n) {
    if (n == 1) return 0;
    if (n == 2) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

/* Recursively prints terms 1..n in order */
void printSeries(int n) {
    if (n == 0) return;            /* base case */
    printSeries(n - 1);            /* print the earlier terms first */
    printf("%d ", fibonacci(n));
}

int main(void) {
    int n;
    printf("Enter number of terms: ");
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("Please enter a positive integer.\n");
        return 1;
    }
    printf("First %d terms: ", n);
    printSeries(n);
    printf("\n");
    return 0;
}
