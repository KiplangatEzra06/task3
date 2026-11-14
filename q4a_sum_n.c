/* Question 4(a): Recursive sum of the first N natural numbers */
#include <stdio.h>

int sumN(int n) {
    if (n <= 0) return 0;          /* base case */
    return n + sumN(n - 1);        /* recursive case */
}

int main(void) {
    int n;
    printf("Enter N: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Please enter a non-negative integer.\n");
        return 1;
    }
    printf("Sum of the first %d natural numbers = %d\n", n, sumN(n));
    return 0;
}
