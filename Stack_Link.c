#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct tStackNode {
	void* data;
	struct tStackNode* next;
}StackNode;
typedef struct {
	int count;
	StackNode* top;
}Stack;
Stack* CreateStack_Link(int size)
{
	Stack* pStack = (Stack*)malloc(sizeof(Stack));
	if (pStack == NULL)
		return NULL;
	pStack->count = 0;
	pStack->top = NULL;
	return pStack;
}
void Push(Stack* pStack,  void* item)
{
	StackNode* pNewNode = (StackNode*)malloc(sizeof(StackNode));
	if (pNewNode == NULL)
		return;
	pNewNode->data = item;
	pNewNode->next = pStack->top;
	pStack->top = pNewNode;
	pStack->count++;
}
void* Pop(Stack* pStack)
{
	if (pStack->top == NULL) 
	{
		return 0;
	}
	StackNode* pTopNode = pStack->top;
	void* data = pTopNode->data;
	pStack->top = pTopNode->next;
	free(pTopNode);           
	pStack->count--;
	return data;
}
void DestroyStack(Stack* pStack)
{
	StackNode* pNode = pStack->top;
	StackNode* pDelete = NULL;
	while (pNode != NULL) {
		pDelete = pNode;
		pNode = pNode->next;
		free(pDelete);  
	}
	pStack->top = NULL;   
	pStack->count = 0;    
}
int IsEmptyStack(Stack* pStack)
{
	return (pStack->top == NULL);
}
void* Top(Stack* pStack)
{
	if (pStack->top == NULL)
		return NULL;
	return pStack->top->data;
}
