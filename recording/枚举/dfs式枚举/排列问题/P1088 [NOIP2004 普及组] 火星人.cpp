#include <iostream>
using namespace std;
int N, M;
int s[10005];
int visit[10005];
int cnt,flag;
void dfs(int now)	//now表示在数组的长度
{/*采用了一个回溯算法的思想

 */
	if (flag)				//说明找到了，直接返回即可
		return;
	if (now >= N)
	{//只有在长度满足时才会开始计数
		cnt++;
		if (cnt == M + 1)			//M+1,+1表示加上给定的顺序
		{
			for (int i = 0;i < N;i++)
				cout << s[i]<<' ';				//直接输出
			flag = 1;
		}
	}
	for (int i = 1;i <= N;i++)
	{
		if (cnt == 0) i = s[now];				
		//如果还没有到达给定序列，就先获得目前下标的值，再把它染色（访问）
		if (!visit[i])
		{
			visit[i] = 1;
			s[now] = i;				//染色
			dfs(now + 1);
			s[now] = 0;				//回溯
			visit[i] = 0;
		}
	}
}
int main()
{
	cnt = 0,flag=0;
	cin >> N >> M;
	for (int i = 0;i < N;i++)
		cin >> s[i];			//扫描数组
	dfs(0);		
	
}