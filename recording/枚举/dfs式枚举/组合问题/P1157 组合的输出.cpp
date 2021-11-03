#include <iostream>
using namespace std;
int n, r;
int b[25];
void dfs(int x, int lenth)
{
	if (lenth >= r || x > n)
	{
		if (lenth == r)
		{
			for (int i = 0;i < lenth;i++)
				printf("%3d", b[i]);
			printf("\n");
		}
		return;
	}
	for (int i = x + 1;i <= n;i++)
	{
		b[lenth] = i;
		dfs(i, lenth + 1);
		b[lenth] = 0;
	}
}
int main()
{
	cin >> n >> r;
	for (int i = 1;i <= n;i++)
	{
		b[0] = i;
		dfs(i, 1);
		b[0] = 0;
	}
}