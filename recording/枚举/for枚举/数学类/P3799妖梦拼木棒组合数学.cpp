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
		num[a]++;				//这个数的出现次数
		MIN = min(MIN, a);
		MAX = max(MAX, a);
	}

	for (int i = MIN+1;i <=MAX;i++)		//从最小值+1开始寻找有没有两根一样的,到MAX完成剪枝
		if (num[i] >= 2)				//只有有两根一样的时，才会停下来操作
		{//这里的i表示的是木棒的长度，num[i]表示的是长度为i的木棒出现的次数
			for (int j = MIN;2*j <= i;j++)
			{	
				if (j != i - j)			//如果两个j不相等，Cn1
					ans += Cn2(num[i]) * Cn1(num[j]) * Cn1(num[i - j])  % KMOD;
				else if (num[j] >= 2 && j * 2 == i)			//如果j相等  Cn2
					ans += Cn2(num[i])*Cn2(num[j]) %KMOD;
			}
		}
	cout << ans%KMOD;
}