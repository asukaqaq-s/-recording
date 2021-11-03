#include <iostream>
#include <cstring>
using namespace std;
int temp[10];
int ans[10000][10];
int number;
int n;
int sum;
void dfs(int x, int len)
{//取当前位的值，取下一位的sum
	temp[len] = x;
	if (len ==9)
	{
		if (n == sum)
		{
			for (int i = 0;i < 10;i++)
				ans[number][i] = temp[i];
			number++;
		}
	}
	if (len >= 9 || x <= 0 || x > 3)
		return;
	
	for (int i = 1;i <= 3;i++)
	{
		sum += i;
		dfs(i, len + 1);
		sum -= i;
		temp[len + 1] = 0;
	}
}
int main()
{
	sum = 0;
	number = 0;
	cin >> n;
	if (n > 30 || n < 10)
	{
		cout << 0;
		return 0;
	}
	for (int i = 1;i <= 3;i++)
	{
		sum += i;
		dfs(i, 0);
		sum -= i;
	}
	cout << number<<endl;
	for (int i = 0;i < number;i++)
	{
		for (int j = 0;j < 10;j++)
			printf("%d ", ans[i][j]);
		printf("\n");
	}
}