#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
	char** queue;
	int size;
	int front, rear;
}Queue;
int IsFullQueue(Queue* pQueue);
int IsEmptyQueue(Queue* pQueue);
Queue* CreateQueue(int size)
{
	Queue* pQueue = (Queue*)malloc(sizeof(Queue));
	if (pQueue == NULL)
		return NULL;
	pQueue->queue = (char**)malloc(size * sizeof(char*));
	if (pQueue->queue == NULL)
	{
		free(pQueue);
		return NULL;
	}
	pQueue->size = size;
	pQueue->front = pQueue->rear = 0;
	return pQueue;
}
void Enqueue(Queue* pQueue, char* item)
{
	if ((pQueue->rear+1)%pQueue->size==pQueue->front)
	{
		printf("Queue is fulled\n");
		return;
	}
	else
	{
		pQueue->rear = (pQueue->rear + 1) % pQueue->size;
		pQueue->queue[pQueue->rear] = (char*)malloc(strlen(item)+1);
		strcpy(pQueue->queue[pQueue->rear], item);
	}
}
char* Dequeue(Queue* pQueue)
{
	if (IsEmptyQueue(pQueue)) {
		printf("Queue is empty!\n");
		return NULL;
	}
	pQueue->front = (pQueue->front + 1) % pQueue->size;
	char* a = pQueue->queue[pQueue->front];
	return a;
}
char* ItemQueue(Queue* pQueue,int n)
{
	int index = (pQueue->front + 1 + n) % pQueue->size;
	return pQueue->queue[index];
}
int IsFullQueue(Queue* pQueue)
{
	if ((pQueue->rear + 1) % pQueue->size == pQueue->front)
		return 1;
	else
		return 0;
}
int IsEmptyQueue(Queue* pQueue)
{
	if (pQueue->rear == pQueue->front)
		return 1;
	else
		return 0;
}
