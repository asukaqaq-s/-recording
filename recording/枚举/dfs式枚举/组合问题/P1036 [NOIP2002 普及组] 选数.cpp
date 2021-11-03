#include <iostream>
#include <cstring>
using namespace std;
int S[25] = { 0 };
int visit[25];
int cnt;
int n, k;				//n代表数据总数，k代表选几个数
bool Issushu(int x)
{
	for (int i = 2;i <= x - 1;i++)
		if (x % i == 0) return false;			//不是素数
	return true;								//是素数
}
void dfs(int last,int k,int sum)
{
	if (k == 0)						//要选的数还剩0，直接退出
	{
		if (Issushu(sum))
			cnt++;
		return;
	}
	for (int i = last;i < n;i++)
	{
		if (!visit[i])				//没有访问过
		{
			visit[i] = 1;
			dfs(i,k - 1, sum +S[i]);
			visit[i] = 0;
		}
	}
}
int main()
{
	cnt = 0;
	cin >> n >> k;
	for (int i = 0;i < n;i++)
		cin >> S[i];
	for (int i = 0;i < n;i++)
	{
		memset(visit, 0, sizeof(visit));
		visit[i] = 1;
		dfs(i,k - 1, 0 + S[i]);
	}
	cout << cnt;
}