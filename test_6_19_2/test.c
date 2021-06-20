#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
typedef struct LNode* LNode;
struct LNode
{
	int data;
	LNode next;
};

LNode Insert(LNode G, int m)
{
	LNode tmp;
	LNode L = (LNode)malloc(sizeof(struct LNode));
	L->data = m;
	L->next = NULL;
	if (G)
	{
		tmp = G->next;
		G->next = L;
		L->next = tmp;
		return G;
	}
	return L;
}

LNode* CreatGraph()
{
	int i, n, v, m;
	//输入节点个数
	scanf("%d", &n);
	if (n <= 0)
		exit(-1);
	LNode* G = (LNode*)malloc(n * sizeof(LNode));
	for (i = 0; i < n; i++)
	{
		G[i] = NULL;
		//输入每个节点的邻接点个数，和他们的序号；
		scanf("%d", &v);
		while (v--)
		{
			scanf("%d", &m);
			G[i] = Insert(G[i], m);
		}
	}

	for (i = 0; i < n; i++)
	{
		while (G[i])
		{
			printf("%d ", G[i]->data);
			G[i] = G[i]->next;
		}
		printf("\n");
	}
	return G;
}

void DFS(LNode G)
{
	visted(G);
}

int main()
{
	//10 2 3 1 4 0 3 2 5 3 1 5 4 4 0 1 6 7 3 2 5 9 6 2 1 6 8 9 4 4 3 7 8 5 2 3 6 3 5 6 9 3 5 8 4
	LNode* G = CreatGraph();
	DFS(G[0]);
	return 0;
}