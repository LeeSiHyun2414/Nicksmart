#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct vertex Vertex;
typedef struct arc Arc;
typedef struct graph Graph;
int DeleteArc(Graph* pGraph, char* from, char* to);
struct arc {
    Vertex* des;
    int weight;
    Arc* next;
};
struct vertex {
    Vertex* next;
    char *data;
    int in;
    int out;
    int processed;
    Arc* pArc;
};
struct graph {
    int count;
    Vertex* first;
};

Graph* CreateGraph_Link()
{
    Graph* pNew = (Graph*)malloc(sizeof(Graph));
    if (pNew == NULL)
        return NULL;
    pNew->count = 0;
    pNew->first = NULL;
    return pNew;
}
Vertex* SearchVertex(Graph* pGraph, char* data)
{
    Vertex* v = pGraph->first;
    while (v)
    {
        if (strcmp(v->data, data) == 0)
            return v;
        v = v->next;
    }
    return NULL;
}

Vertex* InsertVertex(Graph* pGraph, char* data)
{
    if (pGraph == NULL)
        return NULL;
    Vertex* pVer = (Vertex*)malloc(sizeof(Vertex));
    if (pVer == NULL)
        return NULL;

    pVer->data = _strdup(data);  

    pVer->in = pVer->out = pVer->processed = 0;
    pVer->pArc = NULL;
    pVer->next = pGraph->first;
    pGraph->first = pVer;
    pGraph->count++;
    return pVer;
}
int DeleteVertex(Graph* pGraph, char* data)
{
    if (pGraph == NULL || pGraph->first == NULL)return 0;
    Vertex* del = NULL;
    Vertex* temp = pGraph->first;
    while (temp && temp->data != data)
    {
        del = temp;
        temp = temp->next;
    }
    if (temp == NULL)return 0;
    Arc* a = temp->pArc;
    while (a)
    {
        Arc* t = a;
        a = a->next;
        temp->out--;
        t->des->in--;
        free(t);
    }
    Vertex* v = pGraph->first;
    while (v)
    {
        DeleteArc(pGraph, v->data, data);
        v = v->next;
    }

    if (del == NULL) pGraph->first = del->next;
    else del->next = temp->next;

    free(del);
    pGraph->count--;
    return 1;
}
int InsertArc(Graph* pGraph, char* from, char* to, int weight)
{
    Vertex* vfrom = SearchVertex(pGraph, from);
    Vertex* vto = SearchVertex(pGraph, to);
    if (vfrom == NULL || vto == NULL)
        return 0;

    Arc* a = (Arc*)malloc(sizeof(Arc));
    if (a == NULL)
        return 0;

    a->des = vto;
    a->weight = weight;
    a->next = vfrom->pArc;
    vfrom->pArc = a;

    vfrom->out++;
    vto->in++;
    return 1;
}
int DeleteArc(Graph* pGraph, char* from, char* to)
{
    Vertex* vfrom = SearchVertex(pGraph, from);
    Vertex* vto = SearchVertex(pGraph, to);
    if (vfrom == NULL || vto == NULL)
        return 0;
    Arc* prev = NULL;
    Arc* cur = vfrom->pArc;
    while (cur && cur->des != vto)
    {
        prev = cur;
        cur = cur->next;
    }
    if (cur == NULL)
        return 0;
    if (prev == NULL)
        vfrom->pArc = cur->next;
    else
        prev->next = cur->next;
    free(cur);
    vfrom->out--;
    vto->in--;
    return 1;
}
int visited[100];
void DFS(Vertex* root)
{
    int u = root->data[0] - 'A';
    visited[u] = 1;
    printf("%c ", root->data[0]);

    Arc* p = root->pArc;
    while (p)
    {
        int v = p->des->data[0] - 'A';

        if (!visited[v])
            DFS(p->des);

        p = p->next;
    }
}
void BFS(Vertex* root)
{
    int visited2[100] = { 0 };
    Vertex* queue[100];
    int front = 0, rear = 0;

    int start = root->data[0] - 'A';
    visited2[start] = 1;
    queue[rear++] = root;

    while (front < rear)
    {
        Vertex* uVer = queue[front++];
        int u = uVer->data[0] - 'A';

        printf("%c ", uVer->data[0]);

        Arc* p = uVer->pArc;
        while (p)
        {
            int v = p->des->data[0] - 'A';

            if (!visited2[v])
            {
                visited2[v] = 1;
                queue[rear++] = p->des;
            }
            p = p->next;
        }
    }
}
void PrintFrom(Graph* pGraph, char *from)
{
    if (pGraph == NULL)
        return;
    Vertex* v = SearchVertex(pGraph, from);
    if (v == NULL)
        return;
    printf("%s ", v->data);
    Arc* p = v->pArc;
    if (p == NULL)
        return;
    while (p) {
        printf("%s", p->des->data);
        p = p->next;
    }
    printf("\n");
}
int visitedST[100];

void SpanningTree(Vertex* root)
{
    int u = root->data[0] - 'A';
    visitedST[u] = 1;

    Arc* p = root->pArc;
    while (p)
    {
        int v = p->des->data[0] - 'A';
        if (!visitedST[v])
        {
            printf("%c %c (%d)\n", root->data[0], p->des->data[0],p->weight);
            SpanningTree(p->des);
        }
        p = p->next;
    }
}
int MinDist2(int* dist, int* visited, int size)
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

void PrintDist2(int* dist, int size)
{
    for (int i = 0; i < size; i++)
        printf("A %c : %d\n", i + 'A', dist[i]);
    printf("\n");
}

void Dijkstra_Link(Graph* g, char* startData)
{
    int size = g->count;
    int dist[100], visited[100];
    for (int i = 0; i < size; i++) {
        dist[i] = 999999;
        visited[i] = 0;
    }

    int start = startData[0] - 'A';
    dist[start] = 0;

    printf("Shortest path from %c :\n\n", start + 'A');
    PrintDist2(dist, size);

    for (int k = 0; k < size - 1; k++)
    {
        int u = MinDist2(dist, visited, size);
        visited[u] = 1;

        Vertex* v = g->first;
        while (v && v->data[0] - 'A' != u)
            v = v->next;

        Arc* p = v->pArc;
        while (p)
        {
            int to = p->des->data[0] - 'A';
            if (!visited[to] && dist[u] + p->weight < dist[to])
                dist[to] = dist[u] + p->weight;
            p = p->next;
        }

        PrintDist2(dist, size);
    }
}





#define _CRT_SECURE_NO_WARNINGS
#include"Ad_List3.h"
int main(void)
{
	Graph* g = CreateGraph_Link();
	char line[100];
	char pu[2], pv[2], pstart[2];
	char* u = pu;
	char* v = pv;
	char* start = pstart;
	int weight=0;
	FILE* fp = fopen("test.txt", "r");
	if (fp == NULL)
	{
		printf("NO such file\n");
		return 1;
	}
	printf("File name of a graph: test.txt\n");
	printf("The graph is:\n");

	if (fgets(line, sizeof(line), fp) != NULL)
		sscanf(line, " %s ", start);
	while (fgets(line, sizeof(line), fp) != NULL)
	{
		if (strlen(line) <= 1) continue;
		if (sscanf(line, "%s %s %d", u, v,&weight) == 3)
		{
			if (SearchVertex(g, u) == NULL)
				InsertVertex(g, u);
			if (SearchVertex(g, v) == NULL)
				InsertVertex(g, v);
			InsertArc(g, u, v,weight);
		}
	}
	fclose(fp);
	char key[2];
	for (int i = 0; i < g->count; i++) {
		key[0] = 'A' + i;
		key[1] = '\0';
		PrintFrom(g, key);
	}
	printf("\n");
	memset(visited, 0, sizeof(visited));
	Vertex* startVer = SearchVertex(g, start);
	printf("Minimum spannig Tree: \n");
	SpanningTree(startVer);
	Dijkstra_Link(g, start);
}
