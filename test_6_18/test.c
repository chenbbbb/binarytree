#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct Heap
{
	int* v;
	int size;
	int capacity;
} Heap;

Heap* create(int MaxSize)
{
	Heap* H = (Heap*)malloc(sizeof(Heap));
	H->v = (int*)malloc((MaxSize + 1) * sizeof(int));
	H->size = 0;
	H->capacity = MaxSize;
	H->v[0] = 10000;
	return H;
}

int IsFull(Heap* H)
{
	if (H->size == H->capacity)
		return 1;
	else
		return 0;
}

void insert(int v, Heap* H)
{
	int i;
	if (IsFull(H))
	{
		printf("×î´ó¶ÑÒÑÂú\n");
		return;
	}

	H->v[++H->size] = v;
	for (i = H->size; H->v[i / 2] < v; i /= 2)
	{
		H->v[i] = H->v[i / 2];
	}
	H->v[i] = v;
}

void adjust(Heap* H)
{
	int i;
	int parent, child, tmp;
	for (i = H->size / 2; i > 0; i--)
	{
		tmp = H->v[i];
		for (parent = i; parent * 2 <= H->size; parent = child)
		{
			child = parent * 2;
			if (child != H->size && H->v[child] < H->v[child + 1])
				child++;
			if (tmp >= H->v[child])
				break;
			else
				H->v[parent] = H->v[child];
		}
		H->v[parent] = tmp;
	}
}

Heap* ReadyHeap(Heap* H)
{
	int i, n, v;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &v);
		H->v[i] = v;
		H->size++;
	}
	adjust(H);
	return H;
}

void show(Heap* H)
{
	int i;
	for (i = 1; i <= H->size; i++)
	{
		printf("%d ", H->v[i]);
	}
	printf("\n");
}

int DeleteHeap(Heap* H)
{
	int parent, child, max, tmp;
	max = H->v[1];
	tmp = H->v[H->size--];
	for (parent = 1; parent * 2 <= H->size; parent = child)
	{
		child = 2 * parent;
		if (child != H->size && H->v[child] < H->v[child + 1])
			child++;
		if (H->v[child] > tmp)
			H->v[parent] = H->v[child];
		else
			break;
	}
	H->v[parent] = tmp;
	return max;
}

int main()
{ 
	//12 79 66 43 83 30 87 38 55 91 72 49 9
	Heap* H = create(MAXSIZE);
	H = ReadyHeap(H);
	show(H);
	/*show(H);
	DeleteHeap(H);
	show(H);*/
	return 0;
}