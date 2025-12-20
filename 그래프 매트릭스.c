#자료구조 그래프 매트릭스 구현버전 다익스트라, 최소신장트리 포함 코드
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct
{
	int size;
	int** adj;
}Graph;
Graph* CreateGraph(int size)
{
	Graph* pNew = (Graph*)malloc(sizeof(Graph));
	if (pNew == NULL)
		return NULL;
	pNew->size = size;
	pNew->adj = (int**)malloc(size * sizeof(int*));
	if (pNew->adj == NULL)
	{
		free(pNew);
		return NULL;
	}
	for (int i = 0; i < size; i++)
	{
		pNew->adj[i] = (int*)malloc(sizeof(int) * size);
		if (pNew->adj[i] == NULL)
		{
			for (int j = 0; j < i; j++)
				free(pNew->adj[j]);
			free(pNew->adj);
			free(pNew);
			return NULL;
		}
		for (int j = 0; j < size; j++)
			pNew->adj[i][j] = 0;
	}
	return pNew;
}
void DestroyGraph(Graph* pGraph)
{
	if (pGraph == NULL)
		return;
	for (int i = 0; i < pGraph->size; i++)
		free(pGraph->adj[i]);
	free(pGraph->adj);
	free(pGraph);
}
void AddEdge_undir(Graph* pGraph, int u, int v,int weight)
{
	if (pGraph == NULL)
		return;
	if (u < 0 || u >= pGraph->size)
		return;
	if (v < 0 || v >= pGraph->size)
		return;
	pGraph->adj[u][v] = weight;
	pGraph->adj[v][u] = weight;
}
void DeleteEdge_undir(Graph* pGraph, int u, int v)
{
	if (pGraph == NULL)
		return;
	if (u < 0 || u >= pGraph->size)
		return;
	if (v < 0 || v >= pGraph->size)
		return;

	pGraph->adj[u][v] = 0;
	pGraph->adj[v][u] = 0;
}
int IsAdj(Graph* pGraph, int u, int v)
{
	if (pGraph == NULL)
		return 0;
	if (pGraph->adj[u][v] == 1)
		return 1;
	else
		return 0;
}
void PrintEdgesFrom(Graph* pGraph, int u)
{
	if (pGraph == NULL) return;

	printf("%c: ", u + 'A');

	for (int v = 0; v < pGraph->size; v++) {
		if (pGraph->adj[u][v] >= 1) {
			printf("%c(%d) ", v + 'A',pGraph->adj[u][v]);
		}
	}
	printf("\n");
}
int visited[100];
void DFS(Graph* pGraph, int u)
{
	
	visited[u] = 1;
	printf("%c ", u + 'A');   

	for (int i = 0; i < pGraph->size; i++)
	{
		if (pGraph->adj[u][i] == 1 && !visited[i])
		{
			DFS(pGraph, i);
		}
	}
}
void BFS(Graph* g, int start)
{
	int visited[100] = { 0 };
	int queue[100];
	int front = 0, rear = 0;

	visited[start] = 1;
	queue[rear++] = start;

	while (front < rear)
	{
		int u = queue[front++];
		printf("%c ", u + 'A');

		for (int v = 0; v < g->size; v++)
		{
			if (g->adj[u][v] == 1 && !visited[v])
			{
				visited[v] = 1;
				queue[rear++] = v;
			}
		}
	}
}
void PrintGraph(Graph* pGraph)
{
	if (pGraph == NULL)
		return;
	for (int i = 0; i < pGraph->size; i++)
	{
		for (int j = 0; j < pGraph->size; j++)
		{
			printf("%d", pGraph->adj[i][j]);
		}
		printf("\n");
	}
}
int MinKey(int* key, int* mst, int size)
{
	int min = 9999, idx = -1;
	for (int i = 0; i < size; i++)
		if (!mst[i] && key[i] < min) {
			min = key[i];
			idx = i;
		}
	return idx;
}
void Prim(Graph* g, int start)
{
	int size = g->size;
	int key[100], parent[100], mst[100];
	for (int i = 0; i < size; i++) {
		key[i] = 9999;
		mst[i] = 0;
		parent[i] = -1;
	}
	key[start] = 0;
	for (int count = 0; count < size - 1; count++) {
		int u = MinKey(key, mst, size);
		mst[u] = 1;

		for (int v = 0; v < size; v++) {
			if (g->adj[u][v] > 0 && !mst[v] && g->adj[u][v] < key[v]) 
			{
				parent[v] = u;
				key[v] = g->adj[u][v];
			}
		}
	}
	for (int i = 0; i < size; i++)
		if (parent[i] != -1)
			printf("%c %c (%d)\n", parent[i] + 'A', i + 'A', g->adj[i][parent[i]]);
}
int MinDist(int* dist, int* visited, int size)
{
	int min = 999999, idx = -1;
	for (int i = 0; i < size; i++) {
		if (!visited[i] && dist[i] < min) {
			min = dist[i];
			idx = i;
		}
	}
	return idx;
}

void PrintDist(int* dist, int size)
{
	for (int i = 0; i < size; i++) {
		printf("A %c : %d\n", i + 'A', dist[i]);
	}
	printf("\n");
}

void Dijkstra(Graph* g, int start)
{
	int size = g->size;
	int dist[100], visited[100];

	for (int i = 0; i < size; i++) {
		dist[i] = 999999;
		visited[i] = 0;
	}

	dist[start] = 0;

	printf("Shortest path from %c :\n\n", start + 'A');
	PrintDist(dist, size);

	for (int count = 0; count < size - 1; count++) {

		int u = MinDist(dist, visited, size);
		visited[u] = 1;

		for (int v = 0; v < size; v++) {
			if (!visited[v] && g->adj[u][v] > 0 &&
				dist[u] + g->adj[u][v] < dist[v]) {

				dist[v] = dist[u] + g->adj[u][v];
			}
		}

		PrintDist(dist, size);  
	}
}





#define _CRT_SECURE_NO_WARNINGS
#include"Ad_Matrix3.h"
int main(void)
{
	Graph* g = CreateGraph(6);
	char line[100];
	char u, v, start;
	int weight;
	FILE* fp = fopen("test.txt", "r");
	if (fp == NULL)
	{
		printf("NO such file\n");
		return 1;
	}

	printf("File name of a graph: test.txt\n");
	printf("The graph is:\n");

	if (fgets(line, sizeof(line), fp) != NULL)
		sscanf(line, " %c", &start);
	while (fgets(line, sizeof(line), fp) != NULL)
	{
		if (strlen(line) <= 1) continue;
		if (sscanf(line, "%c %c %d", &u, &v,&weight) == 3)
		{
			int idx_u = u - 'A';
			int idx_v = v - 'A';
			AddEdge_undir(g, idx_u, idx_v,weight);
		}
	}
	fclose(fp);
	for (int i = 0; i < g->size; i++)
		PrintEdgesFrom(g, i);
	printf("Minimum spanning Tree: \n");
	Prim(g, 0);
	Dijkstra(g, 0);
	return 0;
}
