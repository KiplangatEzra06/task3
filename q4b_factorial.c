/* Question 4(b): Recursive factorial of a number */
#include <stdio.h>

unsigned long long factorial(int n) {
    if (n <= 1) return 1;          /* base case: 0! = 1! = 1 */
    return n * factorial(n - 1);   /* recursive case */
}

int main(void) {
    int n;
    printf("Enter a number (0 to 20): ");
    if (scanf("%d", &n) != 1 || n < 0 || n > 20) {
        printf("Please enter an integer from 0 to 20 (larger values overflow).\n");
        return 1;
    }
    printf("%d! = %llu\n", n, factorial(n));
    return 0;
}
