/* Question 4(c): Recursive Nth term of the Fibonacci series
 * Series: 0, 1, 1, 2, 3, 5, 8, ...  (term 1 = 0, term 2 = 1)
 */
#include <stdio.h>

int fibonacci(int n) {
    if (n == 1) return 0;          /* base cases */
    if (n == 2) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(void) {
    int n;
    printf("Enter N (N >= 1): ");
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("Please enter a positive integer.\n");
        return 1;
    }
    printf("Term %d of the Fibonacci series = %d\n", n, fibonacci(n));
    return 0;
}
