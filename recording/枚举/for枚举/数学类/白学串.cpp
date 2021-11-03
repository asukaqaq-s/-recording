#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int a[100000];
vector<int> arr;
int main()
{
	
	int v1, v2,check;
	int n;						//数据组数
	int q;						//
	cin >> n>>q;
	for (int i = 0;i < n;i++)
		cin >> a[i];
	while (q--)
	{
		cin >> v1 >> v2;
		if (v1 - v2 >= 40) { cout << "yes"; continue; }
		check = 0;
		arr.clear();
		for (int i = v1 - 1;i < v2;i++)
			arr.push_back(a[i]);
		sort(arr.begin(), arr.end());
		int i;
		for (i = 2;i < arr.size();i++)
			if (arr[i - 1] + arr[i - 2] > arr[i])
				break;
		if (i == arr.size())
			cout << "no" << endl;
		else 
			cout << "yes" << endl;
		
	}
}