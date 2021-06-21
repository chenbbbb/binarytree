#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

#define MaxVex 100
#define INFINITY 65535
#define TRUE 1
#define FALSE 0
typedef char VertexType;
typedef int EdgeType;
typedef int Bool;

Bool visted[MaxVex];


typedef struct
{
	VertexType vexs[MaxVex];
	EdgeType arc[MaxVex][MaxVex];
	int numVertexs;
	int numEdges;
}MGraph;

typedef struct
{
	int data[MaxVex];
	int front;
	int rear;
}Queue;

int LocateVerx(MGraph* G, char c)
{
	int i;
	for (i = 0; i < G->numVertexs; i++)
		if (G->vexs[i] == c)
			break;
	return i;
}

MGraph* CreatMGraph(MGraph* G)
{
	int i, j, m, n;
	char v1, v2;
	if (G == NULL)
		G = (MGraph*)malloc(sizeof(MGraph));
	printf("请输入图的顶点数和边数\n");
	scanf("%d%d", &G->numVertexs, &G->numEdges);
	setbuf(stdin, NULL);

	printf("请输入各顶点的数据\n");
	for (i = 0; i < G->numVertexs; i++)
	{
		scanf("%c", &G->vexs[i]);
	}
	setbuf(stdin, NULL);


	for (i = 0; i < G->numVertexs; i++)
		for (j = 0; j < G->numVertexs; j++)
			G->arc[i][j] = INFINITY;
	printf("请输入各条边的顶点数据和权重\n");
	for (i = 0; i < G->numEdges; i++)
	{
		scanf("%c%c%d", &v1, &v2, &j);
		m = LocateVerx(G, v1);
		n = LocateVerx(G, v2);
		G->arc[m][n] = j;
		G->arc[n][m] = j;
	}
	return G;
}

void DFS(MGraph* G, int v)
{
	int i;
	visted[v] = TRUE;
	printf("%c ", G->vexs[v]);
	for (i = 0; i < G->numVertexs; i++)
		if (G->arc[v][i] != INFINITY && !visted[i])
			DFS(G, i);
}

void DFSTraverse(MGraph* G)
{
	int i;
	for (i = 0; i < G->numVertexs; i++)
		visted[i] = FALSE;
	for(i=0;i<G->numVertexs;i++)
		if (!visted[i])
			DFS(G, i);
}

void InitQueue(Queue* Q)
{
	Q->front = Q->rear = 0;
}

int Isempty(Queue* Q)
{
	if (Q->front == Q->rear)
		return TRUE;
	else
		return FALSE;
}

void DeQueue(Queue* Q, int* i)
{
	if (Q->front == Q->rear)
		return;
	Q->front = (Q->front + 1) % MaxVex;
	*i = Q->data[Q->front];
}

void EnQueue(Queue* Q, int i)
{
	if ((Q->rear + 1) % MaxVex == Q->front)
		return;
	Q->rear = (Q->rear + 1) % MaxVex;
	Q->data[Q->rear] = i;
}

void BFSTraverse(MGraph* G)
{
	int i, j, tmp;
	Queue* Q = (Queue*)malloc(sizeof(Queue));
	InitQueue(Q);

	for (i = 0; i < G->numVertexs; i++)
		visted[i] = FALSE;

	for (i = 0; i < G->numVertexs; i++)
	{
		if (!visted[i])
		{
			visted[i] = TRUE;
			printf("%c ", G->vexs[i]);
			EnQueue(Q, i);
			while (!Isempty(Q))
			{
				DeQueue(Q, &tmp);
				for (j = 0; j < G->numVertexs; j++)
					if (G->arc[tmp][j] != INFINITY && !visted[j])
					{
						visted[j] = TRUE;
						printf("%c ", G->vexs[j]);
						EnQueue(Q, j);
					}
			}
		}
	}
}

int main()
{
	//ab1bc2cd3de4eb5af6fh7hg8gf9
	MGraph* G = NULL;
	G = CreatMGraph(G);
	DFSTraverse(G);
	putchar('\n');
	BFSTraverse(G);
	return 0;
}



















//#include <stdio.h>
//int main()
//{
//	char m, n;
//	scanf("%c%c", &n, &m);
//	printf("%c %c", n, m);
//	return 0;
//}