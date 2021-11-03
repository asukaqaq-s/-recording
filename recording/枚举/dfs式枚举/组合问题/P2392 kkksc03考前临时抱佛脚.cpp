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
��һ���� 3 3 4 5
 ��	3 3 4 5   ��
 �� 3 3 4     �� 5
 �� 3 3 5	  �� 4
 �� 3 3		  �� 4 5
 �� 3 4       �� 3 5
 �� 3 5		  �� 3 4
 */
	if (now >= len)				//����������˲ſ�ʼ�Ƚ�
	{
		MINT = min((int)max(l, r), MINT);
		return;
	}
	l += s[now];				//����������±�Ϊnow����
	dfs(s, len, now + 1);
	l -= s[now];				//����
	r += s[now];				//���������
	dfs(s, len, now + 1);
	r -= s[now];				//����
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
			dfs(p[i], s[i], 0);					//s[i]��ʾ����Ŀ����0�������ڿ��˼�����
			ans += MINT;
		}
	cout << ans;
}