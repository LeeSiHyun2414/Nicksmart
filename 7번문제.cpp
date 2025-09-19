#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define INF 1000000000


int com[101][101];

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);

    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++) 
        {
            if (i == j) com[i][j] = 0;
            else com[i][j] = INF;
        }
    }

    
    for (int i = 0; i < m; i++) 
    {
        int a, b;
        scanf("%d %d", &a, &b);
        com[a][b] = 1;
        com[b][a] = 1;
    }

    int x, k;
    scanf("%d %d", &x, &k);

    
    for (int via = 1; via <= n; via++) 
    {
        for (int i = 1; i <= n; i++) 
        {
            for (int j = 1; j <= n; j++) 
            {
                if (com[i][j] > com[i][via] + com[via][j]) 
                {
                    com[i][j] = com[i][via] + com[via][j];
                }
            }
        }
    }


    int result = com[1][x] + com[x][k];
    if (result >= INF) printf("-1\n");
    else printf("%d\n", result);

    return 0;
}
