#include <iostream>
#include <cstring>
using namespace std;
int S[25] = { 0 };
int visit[25];
int cnt;
int n, k;				//n��������������k����ѡ������
bool Issushu(int x)
{
	for (int i = 2;i <= x - 1;i++)
		if (x % i == 0) return false;			//��������
	return true;								//������
}
void dfs(int last,int k,int sum)
{
	if (k == 0)						//Ҫѡ������ʣ0��ֱ���˳�
	{
		if (Issushu(sum))
			cnt++;
		return;
	}
	for (int i = last;i < n;i++)
	{
		if (!visit[i])				//û�з��ʹ�
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