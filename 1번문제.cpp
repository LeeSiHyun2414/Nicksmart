#define _CRT_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    int x=0, y = 0;
    scanf_s("%d", &n);
    getchar();
    char command[100];
    int k = 0;
    char ch;
    while ((ch = getchar()) != '\n' && k < 99)
    {
        command[k] = ch;
        k++;
    }
    command[k] = '\0';
 
    int i = 0;
    while (command[i]!='\0')
    {
        if (command[i] == ' ') { i++; continue; }
        switch (command[i])
        {
            case 'L':
                if (x > 0)
                    x = x - 1;
                break;
            case 'R':
                if (x < n - 1)
                    x = x + 1;
                break;
            case 'U':
                if (y > 0)
                    y = y - 1;
                break;
            case'D':
                if (y < n - 1)
                    y = y + 1;
                break;
        }
        i++;
    }
    printf("%d %d", x + 1, y + 1);

    return 0;
}

