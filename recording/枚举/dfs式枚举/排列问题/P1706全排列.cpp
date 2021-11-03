#include <iostream>
using namespace std;
int ans[100] = { 0 };
int len;
int n;
int visit[10] = { 0 };

void dfs(int z, int lenth)
{/*visit数组下标从1开始*/
	
	if (z > n || lenth > n)
		return;
	ans[lenth] = z;
	if (lenth == len)
	{
		for (int i = 1;i <= len;i++)
			cout << "    " << ans[i];
		cout << '\n';
		return;
	}
	visit[z] = 1;
	for (int i = 1;i <= n;i++)
	{
		if (!visit[i])
		{
			dfs(i, lenth + 1);
			visit[i] = 0;
		}
	}
	ans[lenth] = 0;
}

int main()
{
	ans[0] = 0;
	cin >> n;			//输入n
	len = n;
	for (int i = 1;i <= n;i++)
	{
		dfs(i, 1);
		visit[i] = 0;
	}
}