/*
* 利用最小堆构造哈夫曼树
*/

#ifndef _HUFFMANTREE_H
#define _HUFFMANTREE_H

#define MAXSIZE 100

#include <stdlib.h>

typedef struct HuffmanTree* HTree;
typedef struct MinHeap* MHeap;

struct HuffmanTree
{
	int weight;
	HTree left;
	HTree right;
};

struct MinHeap
{
	HTree* data;
	int size;
	int capacity;
};

HTree CreateHT(int maxsize);




#endif