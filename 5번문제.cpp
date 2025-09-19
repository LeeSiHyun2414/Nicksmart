#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    long long m; 
    scanf("%d %lld", &n, &m);

    int* rc = (int*)malloc(n * sizeof(int));
    int max_height = 0;

    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &rc[i]);
        if (rc[i] > max_height) 
        {
            max_height = rc[i]; 
        }
    }

    long long left = 0;
    long long right = max_height;
    long long result = 0;

    while (left <= right) 
    {
        long long mid = (left + right) / 2;
        long long sum = 0;

        for (int i = 0; i < n; i++) 
        {
            if (rc[i] > mid) 
            {
                sum += rc[i] - mid;
            }
        }

        if (sum >= m) 
        {
            result = mid;  
            left = mid + 1;
        }
        else 
        {
            right = mid - 1;
        }
    }

    printf("%lld\n", result);
    free(rc);
    return 0;
}