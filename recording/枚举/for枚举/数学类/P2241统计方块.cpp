#include <iostream>
#include <algorithm>
using namespace std;
int n, m;

int main()
{
	long long   ju_num=0, z_num=0;
	cin >> n >> m;
	long long i, j;
	for(long long i=m;i>=0;i--)
		for (long long j = n;j >= 0;j--)
		{
			z_num += min(i,j);			//正方形数目
			ju_num += (m - i) * (n - j);
		}
	cout << z_num<<' ' << ju_num-z_num;
}