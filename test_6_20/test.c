#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

#define MaxVex 255
#define TRUE	1
#define FALSE	0

typedef char VertexType;
typedef int Bool;
Bool visted[MaxVex];

typedef struct EdgeNode
{
	int adjvex;
	struct EdgeNode* next;
}EdgeNode;

typedef struct VertexNode
{
	VertexType data;
	EdgeNode* firstEdge;
}VertexNode, AdjList[MaxVex];

typedef struct Graph
{
	AdjList adjList;
	int numEdges;
	int numVertexs;
}Graph, * GraphAdjList;

typedef struct LoopQueue
{
	int data[MaxVex];
	int front;
	int rear;
}LoopQueue, * Queue;

int LocatVex(GraphAdjList G, char v)
{
	int i;
	for (i = 0; i < G->numVertexs; i++)
	{
		if (G->adjList[i].data == v)
			break;
	}
	return i;
}

void CreatALGraph(GraphAdjList* G)
{
	int i, c, j, k;
	char v1, v2;
	if (*G == NULL)
		*G = (GraphAdjList)malloc(sizeof(Graph));
	printf("请输入图的顶点数和边数:\n");
	scanf("%d%d", &(*G)->numVertexs, &(*G)->numEdges);
	while ((c = getchar()) != EOF && c != '\n');
	printf("=======================\n");
	printf("请输入每个顶点的数据:\n");
	for (i = 0; i < (*G)->numVertexs; i++)
	{
		scanf("%c", &(*G)->adjList[i].data);
		(*G)->adjList[i].firstEdge = NULL;
	}
	while ((c = getchar()) != EOF && c != '\n');
	printf("=======================\n");
	printf("请输入每条边的顶点信息:\n");
	for (i = 0; i < (*G)->numEdges; i++)
	{
		scanf("%c%c", &v1, &v2);
		j = LocatVex(*G, v1);
		k = LocatVex(*G, v2);

		EdgeNode* N1 = (EdgeNode*)malloc(sizeof(EdgeNode));
		N1->adjvex = k;
		N1->next = (*G)->adjList[j].firstEdge;
		(*G)->adjList[j].firstEdge = N1;

		N1 = (EdgeNode*)malloc(sizeof(EdgeNode));
		N1->adjvex = j;
		N1->next = (*G)->adjList[k].firstEdge;
		(*G)->adjList[k].firstEdge = N1;
	}
	while ((c = getchar()) != EOF && c != '\n');
}

void DFS(GraphAdjList G, int i)
{
	visted[i] = TRUE;
	printf("%c ", G->adjList[i].data);

	EdgeNode* p = G->adjList[i].firstEdge;
	while (p)
	{
		if (!visted[p->adjvex])
			DFS(G, p->adjvex);
		p = p->next;
	}
}

void DFSTraverse(GraphAdjList G)
{
	int i;
	for (i = 0; i < G->numVertexs; i++)
		visted[i] = FALSE;
	for (i = 0; i < G->numVertexs; i++)
		if (!visted[i])
			DFS(G, i);
}

void InitQueue(Queue Q)
{
	Q->front = Q->rear = 0;
}

Bool IsFull(Queue Q)
{
	if ((Q->rear + 1) % MaxVex == Q->front)
		return TRUE;
	else
		return FALSE;
}

void EnQueue(Queue Q, int v)
{
	if (!IsFull(Q))
	{
		Q->rear = (Q->rear + 1) % MaxVex;
		Q->data[Q->rear] = v;
	}
}

Bool IsEmpty(Queue Q)
{
	if (Q->front == Q->rear)
		return TRUE;
	else
		return FALSE;
}

void DeQueue(Queue Q, int* pi)
{
	Q->front = (Q->front + 1) % MaxVex;
	*pi = Q->data[Q->front];
}

void BFSTraverse(GraphAdjList G)
{
	int i;
	Queue Q = (Queue)malloc(sizeof(LoopQueue));
	InitQueue(Q);
	for (i = 0; i < G->numVertexs; i++)
		visted[i] = FALSE;
	for (i = 0; i < G->numVertexs; i++)
	{
		if (!visted[i])
		{
			printf("%c ", G->adjList[i].data);
			visted[i] = TRUE;
			EnQueue(Q, i);
			while (!IsEmpty(Q))
			{
				DeQueue(Q, &i);
				EdgeNode* P = G->adjList[i].firstEdge;
				while (P)
				{
					if (!visted[P->adjvex])
					{
						visted[P->adjvex] = TRUE;
						printf("%c ", G->adjList[P->adjvex].data);
						EnQueue(Q, P->adjvex);
					}
					P = P->next;
				}
			}
		}
	}
}

int main()
{
	//abbccddeebaffgghhf
	GraphAdjList G = NULL;
	CreatALGraph(&G);
	DFSTraverse(G);
	BFSTraverse(G);
	return 0;
}