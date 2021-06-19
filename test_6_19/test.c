#define _CRT_SECURE_NO_WARNINGS 1
#define MaxSize 100
#include <stdio.h>

typedef int SetType[MaxSize];

void Initialization(int* s, int n)
{
	int i;
	for (i = 0; i < n; i++)
		s[i] = -1;
}

int Find(SetType s, int a)
{
	for (; s[a] > 0; a = s[a])
		;
	return a;
}

void Union(SetType s, int root1, int root2)
{
	if (s[root1] < s[root2])
	{
		s[root1] += s[root2];
		s[root2] = root1;
	}
	else
	{
		s[root2] += s[root1];
		s[root1] = root2;
	}
}

void InputConnection(SetType s)
{
	int a, b;
	int root1, root2;
	scanf("%d %d\n", &a, &b);
	root1 = Find(s, a-1);
	root2 = Find(s, b-1);
	if (root1 != root2)
		Union(s, root1, root2);
}

void CheckConnection(SetType s)
{
	int a, b;
	int root1, root2;
	scanf("%d %d\n", &a, &b);
	root1 = Find(s, a - 1);
	root2 = Find(s, b - 1);
	if (root1 == root2)
		printf("yes\n");
	else
		printf("no\n");
}

void CheckNetwork(SetType s, int n)
{
	int i, count = 0;
	for (i = 0; i < n; i++)
	{
		if (s[i] < 0)
			count++;
	}
	if (count == 1)
		printf("The network is connected.\n");
	else
		printf("There are %d components.\n", count);
}

int main()
{
	int n;
	char in;
	SetType s;
	scanf("%d\n", &n);
	Initialization(s, n);
	do
	{
		scanf("%c", &in);
		switch (in)
		{
		case 'I':
			InputConnection(s);
			break;
		case 'C':
			CheckConnection(s);
			break;
		case 'S':
			CheckNetwork(s, n);
			break;
		}
	} while (in != 'S');
	return 0;
}