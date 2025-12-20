#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct tQueueNode {
	char** data;
	struct tQueueNode* next;
}QueueNode;
typedef struct
{
	int count;
	QueueNode* front, * rear;
}Queue;
Queue* CreateQueue_Link(int size)
{
	Queue* pQueue = (Queue*)malloc(sizeof(Queue));
	if (pQueue == NULL)
		return NULL;
	pQueue->count = 0;
	pQueue->front = pQueue->rear = NULL;
	return pQueue;
}
void Enqueue(Queue* pQueue, char* item)
{
	QueueNode* pNewQueue = (QueueNode*)malloc(sizeof(QueueNode));
	if (pNewQueue == NULL)
		return;
	strcpy(*pNewQueue->data, item);
	pNewQueue->next = NULL;
	if (pQueue->count <= 0)
	{
		pQueue->front = pQueue->rear = pNewQueue;
	}
	else
	{
		pQueue->rear->next = pNewQueue;
		pQueue->rear = pNewQueue;
	}
	pQueue->count++;
}
char* Dequeue(Queue* pQueue)
{
	QueueNode* pFront = NULL;
	char* item;
	if (pQueue->count <= 0)
		return 0;
	pFront = pQueue->front;
	item = *pFront->data;
	if (pQueue->count == 1)
		pQueue->front = pQueue->rear = NULL;
	else
		pQueue->front = pFront->next;
	free(pFront);
	pQueue->count--;
	return item;
}
char* ItemQueue(Queue* pQueue, int index)
{
	char* item = 0;
	while (index)
	{
		*pQueue->front->data = item;
	}
	return item;
}
void DestroyQueue(Queue* pQueue)
{
	QueueNode* temp;
	while (pQueue->front != NULL)
	{
		temp = pQueue->front;
		pQueue->front = pQueue->front->next;
		free(temp);
	}
	free(pQueue);
}
