#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int compare(void* a, void* b);
typedef struct {
	void** heap;
	int index;
	int (*compare)(void* a, void* b);
	int size;
}Heap;
Heap* CreateHeap(int size,int(*compare)(void*a,void*b))
{
	Heap* pHeap = (Heap*)malloc(sizeof(Heap));
	if (pHeap == NULL)
		return NULL;
	pHeap->index = 0;
	pHeap->compare = compare;
	pHeap->size = size;
	pHeap->heap = (void**)malloc(sizeof(void*)*size);
	return pHeap;
}
void ReheapUp(Heap* pHeap, int index);
void ReheapDown(Heap* pHeap, int index);
void ReheapDown_down(Heap* pHeap, int index);
void InsertHeap(Heap* pHeap, void*data)
{
	if (pHeap->index >= pHeap->size)
		return;
	pHeap->heap[pHeap->index++] = data;
	ReheapUp(pHeap, pHeap->index - 1);
}
void ReheapUp(Heap* pHeap, int index)
{
	if (index <= 0 || index >= pHeap->index)
		return;
	int parent = 0;
	parent = (index - 1) / 2;
	if (pHeap->compare(pHeap->heap[index],pHeap->heap[parent])>0)
	{
		void* temp = pHeap->heap[parent];
		pHeap->heap[parent] = pHeap->heap[index];
		pHeap->heap[index] = temp;
		ReheapUp(pHeap, parent);
	}
}
void ReheapUp_down(Heap* pHeap, int index)
{
	if (index <= 0 || index >= pHeap->index)
		return;
	int parent = 0;
	parent = (index - 1) / 2;
	if (pHeap->compare(pHeap->heap[index], pHeap->heap[parent]) < 0)
	{
		void* temp = pHeap->heap[parent];
		pHeap->heap[parent] = pHeap->heap[index];
		pHeap->heap[index] = temp;
		ReheapUp_down(pHeap, parent);
	}
}
int DeleteHeap(Heap* pHeap, void**item)
{
	if (pHeap->index == 0)
		return 0;
	*item = pHeap->heap[0];
	pHeap->heap[0] = pHeap->heap[--pHeap->index];
	ReheapDown(pHeap, 0);
	return 1;
}
int DeleteHeap_down(Heap* pHeap, void** item)
{
	if (pHeap->index == 0)
		return 0;
	*item = pHeap->heap[0];
	pHeap->heap[0] = pHeap->heap[--pHeap->index];
	ReheapDown_down(pHeap, 0);
	return 1;
}
void ReheapDown(Heap* pHeap, int index)
{
	if (index < 0 || pHeap->index < index)
		return;
	if (index * 2 + 1 < pHeap->index)
	{
		int max = index * 2 + 1;
		if (max + 1 < pHeap->index && pHeap->compare(pHeap->heap[max], pHeap->heap[max + 1]) < 0)
			max++;
		if (pHeap->compare(pHeap->heap[max], pHeap->heap[index]) > 0)
		{
			void* temp = pHeap->heap[index];
			pHeap->heap[index] = pHeap->heap[max];
			pHeap->heap[max] = temp;
			ReheapDown(pHeap, max);
		}
	}
}
void ReheapDown_down(Heap* pHeap, int index)
{
	if (index < 0 || pHeap->index < index)
		return;
	if (index * 2 + 1 < pHeap->index)
	{
		int max = index * 2 + 1;
		if (max + 1 < pHeap->index && pHeap->compare(pHeap->heap[max], pHeap->heap[max + 1]) > 0)
			max++;
		if (pHeap->compare(pHeap->heap[max], pHeap->heap[index]) < 0)
		{
			void* temp = pHeap->heap[index];
			pHeap->heap[index] = pHeap->heap[max];
			pHeap->heap[max] = temp;
			ReheapDown_down(pHeap, max);
		}
	}
}
void BuildHeap(Heap* pHeap)
{
	int i = 0;
	for (i = 1; i < pHeap->index; i++)
		ReheapUp(pHeap, i);
}
void BuildHeap_down(Heap* pHeap)
{
	int i = 0;
	for (i = 1; i < pHeap->index; i++)
		ReheapUp_down(pHeap, i);
}
