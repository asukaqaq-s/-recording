#include <iostream>
using namespace std;
int N, M;
/*����˼�룺�ݹ�	��һ��ȫȾ�ɰף�*/
char a[52][52];
int ans;
int main()
{
	int cnt = 0;
	int b1 =0,b2 = 0,b3=0;
	cin >> N >> M;
	for (int i = 0;i < N;i++)
		for (int j = 0;j < M;j++)
			cin >> a[i][j];
	ans = 10000000;
	for (int i = 0;i < N - 2;i++)
	{	//��0�е�i��ȫ�滻Ϊ��
		cnt = 0;
		for (int a1 = 0;a1 <= i;a1++)
			for (int k = 0;k < M;k++)
				if (a[a1][k] != 'W') cnt++;
		b1 = cnt;
		for (int j = i + 1;j < N - 1;j++)
		{//��i+1�е�j��ȫ�滻Ϊ��ɫ
			cnt = b1;
			for (int a1 = i + 1;a1 <= j;a1++)
				for (int k = 0;k < M;k++)
					if (a[a1][k] != 'B') cnt++;
			b2 = cnt;
			cnt = b2;
			for (int z = j + 1;z < N;z++)
				//��j+1�е����һ��ȫ�滻Ϊ��ɫ
			{
				for (int k = 0;k < M;k++)
					if (a[z][k] != 'R') cnt++;
			}
			ans = min(ans, cnt);

		}
	}
	cout << ans;
}