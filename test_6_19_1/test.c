#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
int** CreatGraph(int* sz)
{
	int i, j, v, m, n;
	//printf("请输入图的顶点数\n");
	scanf("%d", &v);
	*sz = v;
	int** p;
	p = (int **)malloc(v * sizeof(int*));
	for (i = 0; i < v; i++)
	{
		p[i] = (int*)malloc(v * sizeof(int));
		for (j = 0; j < v; j++)
			p[i][j] = 0;
		//printf("请输入%d号顶点邻接点个数\n", i);
		scanf("%d", &n);
		while (n--)
		{
			//printf("请输入%d号顶点邻接点的序号\n", i);
			scanf("%d", &m);
			p[i][m] = 1;
		}
	}
	return p;
}

void Show(int** g, int n)
{
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			printf("%d ", g[i][j]);
		printf("\n");
	}
}

int* CreatG(int* sz)
{
	int* p;
	int i, n, m, v, b;
	scanf("%d", &n);
	m = n * (n + 1) / 2;
	*sz = n;
	p = (int*)malloc(m * sizeof(int));
	for (i = 0; i < m; i++)
		p[i] = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &v);
		while (v--)
		{
			scanf("%d", &b);
			p[i * (i + 1) / 2 + b] = 1;
		}
	}
	return p;
}

void ShowG(int* g, int n)
{
	int i, j, m = 0;
	for (i = 1; i <= n; i++) {
		for (j = 0; j < i; j++)
			printf("%d ", g[m++]);
		printf("\n");
	}

}

int main()
{
	//10 2 3 1 4 0 3 2 5 3 1 5 4 4 0 1 6 7 3 2 5 9 6 2 1 6 8 9 4 4 3 7 8 5 2 3 6 3 5 6 9 3 5 8 4
	/*int** g;
	int n;
	g = CreatGraph(&n);
	Show(g, n);*/
	int* g;
	int n;
	//10 0 1 0 1 1 2 0 1 1 2 3 1 2 4 2 3 5 2 3 6 2 5 6 3 4 5 8
	g = CreatG(&n);
	ShowG(g, n);


	return 0;
}