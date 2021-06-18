#include "HuffmanTree.h"



MHeap CreateMH(int maxsize)
{
	MHeap M = (MHeap)malloc(sizeof(struct MinHeap));
	M->data = (HTree*)malloc((maxsize + 1) * sizeof(HTree));
	M->capacity = maxsize;
	M->size = 0;
	//M->data[0] = NULL;
	return M;
}

HTree CreateHT(int maxsize)
{
	int i, n;
	HTree T;
	MHeap M = CreateMH(maxsize);
	n = M->size;
	for (i = 1; i < n; i++)
	{
		T = (HTree)malloc(sizeof(struct HuffmanTree));
		T->left = DeleteHeap(M);
		T->right = DeleteHeap(M);
		T->weight = T->left->weight + T->right->weight;
		InsertHeap(T, M);
	}
	T = DeleteHeap(M);
	FreeH(M);
	return T;
}