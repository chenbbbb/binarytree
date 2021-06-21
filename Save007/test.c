#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

#define YES 1
#define NO 0
#define MAX 100
#define ABS(x) ((x)<0?(-x):(x))

int visted[MAX];
int N;
int d;
struct Point
{
	int x;
	int y;
} Point[MAX];

void ResetVisted()
{
	int i;
	for (i = 0; i < MAX; i++)
		visted[i] = 0;
}

int FirstJump(int i)
{
	if ((d + 7.5) * (d + 7.5)>= ((double)Point[i].x * Point[i].x + (double)Point[i].y * Point[i].y))
		return YES;
	else
		return NO;
}

int IsSafe(int i)
{
	
	if (ABS(Point[i].x) + d >= 50 || ABS(Point[i].y) + d >= 50)
		return YES;
	else
		return NO;
}

int Jump(int i, int j)
{
	if ((Point[i].x - Point[j].x) * (Point[i].x - Point[j].x) +
		(Point[i].y - Point[j].y) * (Point[i].y - Point[j].y) <= d * d)
		return YES;
	else
		return NO;

}

int DFS(int i)
{
	
	int j, answer = NO;
	visted[i] = 1;
	if (IsSafe(i))
		answer = YES;
	else
	{
		for (j = 0; j < N; j++)
		{
			if (!visted[j] && Jump(i, j))
			{
				answer = DFS(j);
				if (answer == YES)
					break;
			}
		}
	}
	return answer;
}

void Save007()
{
	int i, answer = NO;
	ResetVisted();
	for (i = 0; i < N; i++)
	{
		if (!visted[i] && FirstJump(i))
			answer = DFS(i);
		if (answer == YES)
			break;
	}
	if (answer == YES)
		printf("Yes\n");
	else
		printf("No\n");
}

int main()
{
	int i,ret;
	ret = scanf("%d%d", &N, &d);
	for (i = 0; i < N; i++)
	{
		ret = scanf("%d%d", &Point[i].x, &Point[i].y);
	}
	Save007();
	return 0;
}


