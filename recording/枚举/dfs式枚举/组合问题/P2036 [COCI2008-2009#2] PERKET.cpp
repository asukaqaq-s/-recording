#include <iostream>
#include <algorithm>
#include <cstring>
#include <math.h>
using namespace std;
int n;
struct a
{
	int s;			//Ëá¶È
	int b;			//¿à¶È
}food[12];
int SUAN;
int KU;
int MIN;
int visit[12];
void dfs(int x, int len)
{
	if (len > n) return;
	MIN = min(MIN,(int) fabs(SUAN - KU));
	for (int i = x + 1;i < n;i++)
	{
		SUAN *= food[i].s;
		KU += food[i].b;
		visit[i] = 1;
		dfs(i, 0);
		visit[i] = 0;
		SUAN /= food[i].s;
		KU -= food[i].b;
	}
}
int main()
{
	MIN = 1e9;
	SUAN = 1, KU = 0;
	cin >> n;
	for (int i = 0;i < n;i++)
		cin >> food[i].s >> food[i].b;
	for (int i = 0;i < n;i++)
	{
		memset(visit, 0, sizeof(visit));
		SUAN *= food[i].s;
		KU += food[i].b;
		visit[i] = 1;
		dfs(i, 0);
		visit[i] =0;
		SUAN /= food[i].s;
		KU -= food[i].b;
	}
	cout << MIN;
}