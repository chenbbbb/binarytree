#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <stdlib.h>
//typedef struct LNode
//{
//	int data;
//	struct LNode* next;
//} List;
//
//List* attach(List* L1, List* L2)
//{
//	if (!L1)
//		return L2;
//	List* tmp = L1;
//	while (tmp->next)
//		tmp = tmp->next;
//	tmp->next = L2;
//	return L1;
//}
//
//List* create()
//{
//	List* L = NULL, *tmp;
//	int n, data;
//	printf("请输入链表的长度\n");
//	scanf("%d", &n);
//	while (n--)
//	{
//		scanf("%d", &data);
//		tmp = (List*)malloc(sizeof(List));
//		tmp->data = data;
//		tmp->next = NULL;
//		L = attach(L, tmp);
//	}
//	return L;
//}
//
//void ShowList(List* L1)
//{
//	while (L1)
//	{
//		printf("%d ", L1->data);
//		L1 = L1->next;
//	}
//	printf("\n");
//}
//
//List* reverse(int k, List* L)
//{
//	List* front, * rear, * tmp;
//	List* L1 = (List*)malloc(sizeof(List));
//	L1->next = NULL;
//	L1 = attach(L1, L);
//	front = L1->next;
//	rear = front->next;
//	while (--k)
//	{
//		tmp = rear->next;
//		rear->next = front;
//		front = rear;
//		rear = tmp;
//	}
//	L1->next->next = rear;
//	free(L1);
//	return front;
//}
//
//int main()
//{
//	//6 1 2 3 4 5 6
//	List* L1 = create();
//	ShowList(L1);
//	List* L2 = reverse(4, L1);
//	ShowList(L2);
//	return 0;
//}





//
//
//#include <stdio.h>
//#include <stdlib.h>
//typedef struct TNode
//{
//	int V;
//	struct TNode* left;
//	struct TNode* right;
//	int flag;
//}TNode;
//
//TNode* insert(TNode* T, int v)
//{
//	if (!T)
//	{
//		T = (TNode*)malloc(sizeof(struct TNode));
//		T->V = v;
//		T->left = T->right = NULL;
//		T->flag = 0;
//	}
//	else
//	{
//		if (v > T->V)
//			T->right = insert(T->right, v);
//		else if (v < T->V)
//			 T->left = insert(T->left, v);
//	}
//	return T;
//}
//
//TNode* CreatTree(int n)
//{
//	int i, v;
//	TNode* T = NULL;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &v);
//		T = insert(T, v);
//	}
//	return T;
//}
//
//int check(TNode* T, int v)
//{
//	if (T->flag)
//	{
//		if (v > T->V)
//			return check(T->right, v);
//		else if (v < T->V)
//			return check(T->left, v);
//		else
//			return 0;
//	}
//	else
//	{
//		if (v == T->V)
//		{
//			T->flag = 1;
//			return 1;
//
//		}
//		else
//			return 0;
//	}
//}
//
//int judge(TNode* T, int n)
//{
//	int i, v, flag = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &v);
//		if(!flag && !check(T, v))
//			flag = 1;
//	}
//	return flag;
//}
//
//void setzero(TNode* T)
//{
//	if (T->left)
//		setzero(T->left);
//	if (T->right)
//		setzero(T->right);
//	T->flag = 0;
//}
//
//void FreeTree(TNode* T)
//{
//	if (T->left)
//		FreeTree(T->left);
//	if (T->right)
//		FreeTree(T->right);
//	free(T);
//}
//
//int main()
//{
///*
//*已知一个给定的二叉搜查树可由多种不同的插入序列得到
//*现在编写一个程序判断由不同插入序列得到的二叉搜查树是否是同一个
//4 2
//3 1 4 2
//3 4 1 2
//3 2 4 1
//2 1
//2 1
//1 2
//0
//* 
//*/
//	int n, i, L;
//	TNode* T;
//	scanf("%d", &n);
//	while (n)
//	{
//		scanf("%d", &L);
//		T = CreatTree(n);
//		for (i = 0; i < L; i++)
//		{	
//			if (!judge(T, n))
//				printf("Yes\n");
//			else
//				printf("No\n");
//			setzero(T);
//		}
//		FreeTree(T);
//		scanf("%d", &n);
//	}
//	return 0;
//}

#include <stdio.h>

typedef struct MaxHeap
{
	int* arr;
	int size;
	int capacity;
};

int main()
{
	return 0;
}