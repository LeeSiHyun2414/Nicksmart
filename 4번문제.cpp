#define _CRT_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
   int n, k;
    int sum=0;
   scanf_s("%d %d", &n, &k);
   int* a = (int*)malloc(n * sizeof(int));
   int* b = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) 
    {
        scanf_s("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) 
    {
        scanf_s("%d", &b[i]);
    }
    
    for (int i = 0; i < k; i++)
    {
        int min_index = 0;
        int max_index = 0;
        for (int j=1; j < n; j++)
        {
            if (a[j] < a[min_index])
                min_index = j;
        }
        for (int m=1; m < n; m++)
        {
            if (b[m] > b[max_index])
                max_index = m;
        }
        if (b[max_index] > a[min_index])
        {
            int temp = a[min_index];
            a[min_index] = b[max_index];
            b[max_index] = temp;
        }
        else
            break;
    }

    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    printf("%d", sum);
    free(a);
    free(b);
    return 0;
}