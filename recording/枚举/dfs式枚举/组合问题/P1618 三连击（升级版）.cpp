#include <iostream>
#include <cstring>
using namespace std;
int visit[10];
int Count;
bool check(int x, int y, int z)
{
	int t=0;
	int a[3] = { x,y,z };
	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			t = a[i] % 10;
			a[i] /= 10;
			visit[t]++;
		}
	}
	for (int i = 0;i < 10;i++)
		if (visit[i] > 1||visit[0]>=1)
			return false;
	return true;
}
int main()
{
	Count = 0;
	double A, B, C;					//A,B,CҲҪ����Ϊ��������Ȼ/��ǿתΪ����
	double t1=0,t2 = 0;				//��������Ϊ����
	cin >> A >> B >> C;
	t1 = B / A;t2 = C / A;
	int n=0, m=0;					
	for (int i = 1;i <= 999;i++)
	{
		memset(visit, 0, sizeof(visit));		//���visit����
		n = t1 * i;m = t2 * i;					
		if (n >= 1000 || m >= 1000)				//����1000ֱ��������û������
			continue;
		if (check(i,n,m))						//�ж��Ƿ����ظ�������
		{
			Count++;
			printf("%d %d %d\n", i, n, m);
		}
	}
	if (Count == 0)
		cout << "No!!!";
}