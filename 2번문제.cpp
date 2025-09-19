#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int n, m;
int** ice;
int visited[100][100];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void DFS(int x, int y) {
    visited[x][y] = 1;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if (ice[nx][ny] == 0 && !visited[nx][ny]) {
                DFS(nx, ny);
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    ice = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
        ice[i] = (int*)malloc(m * sizeof(int));

    for (int i = 0; i < n; i++) {
        char line[101];
        scanf("%s", line); 
        for (int j = 0; j < m; j++)
            ice[i][j] = line[j] - '0';
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (ice[i][j] == 0 && !visited[i][j]) {
                DFS(i, j);
                count++;
            }
        }
    }

    printf("%d\n", count);

    for (int i = 0; i < n; i++) free(ice[i]);
    free(ice);

    return 0;
}
