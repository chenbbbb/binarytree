#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
typedef struct tnode
{
	int data;
	struct tnode* left;
	struct tnode* right;
}*bintree;

bintree creat()
{
	int n;
	bintree bt;
	scanf("%d", &n);
	if (n == 0)
		return NULL;
	bt = (bintree)malloc(sizeof(struct tnode));
	bt->data = n;
	bt->left = creat();
	bt->right = creat();
	return bt;
}

bintree search(int x, bintree bt)
{
	if (!bt)
		return NULL;
	if (x > bt->data)
		return search(x, bt->right);
	else if (x < bt->data)
		return search(x, bt->left);
	else
		return bt;
}

void preorder(bintree bt)
{
	if (bt)
	{
		preorder(bt->left);
		printf("%d ", bt->data);
		preorder(bt->right);
	}
}

bintree insert(int n, bintree bt)
{
	if (!bt)
	{
		bt = (bintree)malloc(sizeof(struct tnode));
		bt->data = n;
		bt->left = NULL;
		bt->right = NULL;
		return bt;
	}
	if (n > bt->data)
		bt->right = insert(n, bt->right);
	else if (n < bt->data)
		bt->left = insert(n, bt->left);
	return bt;
}

bintree findmin(bintree bt)
{
	if (!bt)
		return NULL;
	if (!bt->left)
		return bt;
	else
		return findmin(bt->left);
}

bintree deletetree(int n, bintree bt)
{
	bintree temp;
	if (!bt)
		return NULL;
	if (n > bt->data)
		bt->right = deletetree(n, bt->right);
	else if (n < bt->data)
		bt->left = deletetree(n, bt->left);
	else
	{
		if (bt->left && bt->right)
		{
			temp = findmin(bt->right);
			bt->data = temp->data;
			bt->right = deletetree(bt->data, bt->right);
		}
		else
		{
			temp = bt;
			if (!bt->left)
			{
				bt = bt->right;
			}
			else if(!bt->right)
			{
				bt = bt->left;
			}
			free(temp);
		}
	}
	return bt;
}

int main()
{
	//30 15 0 0 41 33 0 0 50 0 0
	printf("请输入二叉搜查树的前序序列\n");
	bintree bt = creat();
	//preorder(bt);
	bintree bn = search(30,bt);
	bintree bt2 = insert(35, bt);
	bintree bt3 = deletetree(41, bt);
	preorder(bt2);
	return 0;
}