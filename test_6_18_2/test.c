#define _CRT_SECURE_NO_WARNINGS 1
#define CAPACITY 5

#include <stdio.h>
#include <stdlib.h>

typedef struct HuffmanTree* HuffmanTree;
typedef struct MinHeap* MinHeap;

struct HuffmanTree
{
	int weight;
	HuffmanTree left;
	HuffmanTree right;
};

struct MinHeap
{
	HuffmanTree* data;
	int size;
	int capacity;
};

MinHeap Adjust(MinHeap H)
{
	int i;
	int parent, child, tmp;
	for (i = H->size / 2; i > 0; i--)
	{
		tmp = H->data[i]->weight;
		for (parent = i; 2 * parent <= H->size; parent = child)
		{
			child = 2 * parent;
			if (child != H->size && H->data[child]->weight > H->data[child + 1]->weight)
				child++;
			if (tmp > H->data[child]->weight)
				H->data[parent]->weight = H->data[child]->weight;
			else
				break;
		}
		H->data[parent]->weight = tmp;
	}
	return H;
}

MinHeap CreatMinHeap(int capacity)
{
	int i;
	MinHeap H = (MinHeap)malloc(sizeof(struct MinHeap));
	H->capacity = capacity;
	H->size = 0;
	H->data = (HuffmanTree*)malloc((H->capacity + 1) * sizeof(HuffmanTree));
	H->data[0] = (HuffmanTree)malloc(sizeof(struct HuffmanTree));
	H->data[0]->weight = -10000;
	H->data[0]->left =	NULL;
	H->data[0]->right =	NULL;
	for (i = 1; i <= H->capacity; i++)
	{
		*(H->data+i) = (HuffmanTree)malloc(sizeof(struct HuffmanTree));
		scanf("%d", &((*(H->data + i))->weight));
		(*(H->data + i))->left = NULL;
		(*(H->data + i))->right = NULL;
		H->size++;
	}
	return Adjust(H);
}

HuffmanTree DeleteHeap(MinHeap H)
{
	if (H->size == 0)
		exit(-1);
	HuffmanTree T = H->data[1];
	H->data[1] = H->data[H->size--];
	H = Adjust(H);
	return T;
}

void Insert(HuffmanTree T, MinHeap H)
{
	if (H->size == H->capacity)
		exit(-1);
	H->data[++H->size] = T;
	H = Adjust(H);
}

void FreeHeap(MinHeap H)
{
	free(H->data);
	free(H);
}

HuffmanTree CreatHuffmanTree(int capacity)
{
	int i, n;
	HuffmanTree T;
	MinHeap H = CreatMinHeap(capacity);
	n = H->size;
	for (i = 1; i < n; i++)
	{
		T = (HuffmanTree)malloc(sizeof(struct HuffmanTree));
		T->left = DeleteHeap(H);
		T->right = DeleteHeap(H);
		T->weight = T->left->weight + T->right->weight;
		Insert(T, H);
	}
	T = DeleteHeap(H);
	FreeHeap(H);
	return T;
}

void Show(HuffmanTree H)
{
	if (H)
	{
		printf("%d ", H->weight);
		Show(H->left);
		Show(H->right);
	}
}

int main()
{
	HuffmanTree H = CreatHuffmanTree(CAPACITY);

	Show(H);
	return 0;
}