#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    int** maze = (int**)malloc(n * sizeof(int*));
    int** dist = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        maze[i] = (int*)malloc(m * sizeof(int));
        dist[i] = (int*)malloc(m * sizeof(int));
        memset(dist[i], 0, m * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        char line[201];
        scanf("%s", line);
        for (int j = 0; j < m; j++) maze[i][j] = line[j] - '0';
    }

    int* qx = (int*)malloc(n * m * sizeof(int)); 
    int* qy = (int*)malloc(n * m * sizeof(int)); 
    int front = 0, rear = 0;

    
    qx[rear] = 0; qy[rear] = 0; rear++;
    dist[0][0] = 1;

    int dx[4] = { -1,1,0,0 };
    int dy[4] = { 0,0,-1,1 };

    while (front < rear) {
        int x = qx[front];
        int y = qy[front];
        front++;

        if (x == n - 1 && y == m - 1) {
            printf("%d\n", dist[x][y]);
            break;
        }

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (maze[nx][ny] == 1 && dist[nx][ny] == 0) {
                    dist[nx][ny] = dist[x][y] + 1;
                    qx[rear] = nx; qy[rear] = ny; rear++;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) { free(maze[i]); free(dist[i]); }
    free(maze); free(dist); free(qx); free(qy);

    return 0;
}

