#include <stdio.h>

long long fib[91]; 

long long fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    if (fib[n] != 0) return fib[n]; 

    fib[n] = fibonacci(n - 1) + fibonacci(n - 2); 
    return fib[n];
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%lld\n", fibonacci(n));

    return 0;
}
