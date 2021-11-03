#include <iostream>
#include <algorithm>
#include <cstring>
int KMOD = 1e9 + 7;
using namespace std;
int n;
int num[5005];
long long ans;
int Cn1(int n)
{
	return n%KMOD;
}
int Cn2(long long n)
{
	return (n * (n - 1) / 2)%KMOD;
}

int main()
{
	int MIN = 1E9, MAX = -1;
	memset(num, 0, sizeof(num));
	ans = 0;
	cin >> n;
	int a;
	for (int i = 0;i < n;i++)
	{
		cin>> a;
		num[a]++;				//������ĳ��ִ���
		MIN = min(MIN, a);
		MAX = max(MAX, a);
	}

	for (int i = MIN+1;i <=MAX;i++)		//����Сֵ+1��ʼѰ����û������һ����,��MAX��ɼ�֦
		if (num[i] >= 2)				//ֻ��������һ����ʱ���Ż�ͣ��������
		{//�����i��ʾ����ľ���ĳ��ȣ�num[i]��ʾ���ǳ���Ϊi��ľ�����ֵĴ���
			for (int j = MIN;2*j <= i;j++)
			{	
				if (j != i - j)			//�������j����ȣ�Cn1
					ans += Cn2(num[i]) * Cn1(num[j]) * Cn1(num[i - j])  % KMOD;
				else if (num[j] >= 2 && j * 2 == i)			//���j���  Cn2
					ans += Cn2(num[i])*Cn2(num[j]) %KMOD;
			}
		}
	cout << ans%KMOD;
}