#include <iostream>
#include<algorithm>
#include <cstring>
using namespace std;
int MINT;
int ans;
int l, r;
int visit[25];
int a[25], b[25], c[25], d[25];
void dfs(int s[],int len,int now)
{/*
有一串题 3 3 4 5
 左	3 3 4 5   右
 左 3 3 4     右 5
 左 3 3 5	  右 4
 左 3 3		  右 4 5
 左 3 4       右 3 5
 左 3 5		  右 3 4
 */
	if (now >= len)				//如果分配完了才开始比较
	{
		MINT = min((int)max(l, r), MINT);
		return;
	}
	l += s[now];				//分配给左脑下标为now的题
	dfs(s, len, now + 1);
	l -= s[now];				//回溯
	r += s[now];				//分配给右脑
	dfs(s, len, now + 1);
	r -= s[now];				//回溯
}
int main()
{
	int s[4];
	cin >> s[0] >> s[1] >> s[2] >> s[3];
	int* p[4] = { a,b,c,d };
	for (int i = 0;i < 4;i++)
		for (int j = 0;j < s[i];j++)
			cin >> p[i][j];

	for (int i = 0;i < 4;i++)
		{
			MINT = 1e9;l = r = 0;
			dfs(p[i], s[i], 0);					//s[i]表示总题目数，0代表现在看了几道题
			ans += MINT;
		}
	cout << ans;
}