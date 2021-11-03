#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int k1, k2;
int a, b;			//区间
int SET(int x)
{
	int i = 0;
	while (x != 0) i++, x /= 10;
	return i;
}
void dfs(int now, int end)
{
	if (now == end)	//长度满了
	{
		if()
	}
}
int main()
{
	cin >> a >> b;
	int A=SET(a);
	int B = SET(b);
	int c[2]={ 5,7 };
	for (int i = A;i <= B;i++)
	{
		if (i == 1)
		{
			for (int j = 0;j < 2;j++)
				if (a <= c[j] && c[j] <= b)
					printf("%d", c[j]);
		}
		if (i == 2)
			printf("%d", i);
		if (i % 2 == 0) continue;
		else	//3,5,7
			dfs(0, i);
	}
}