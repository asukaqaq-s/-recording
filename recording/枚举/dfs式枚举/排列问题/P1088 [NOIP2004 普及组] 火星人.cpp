#include <iostream>
using namespace std;
int N, M;
int s[10005];
int visit[10005];
int cnt,flag;
void dfs(int now)	//now��ʾ������ĳ���
{/*������һ�������㷨��˼��

 */
	if (flag)				//˵���ҵ��ˣ�ֱ�ӷ��ؼ���
		return;
	if (now >= N)
	{//ֻ���ڳ�������ʱ�ŻῪʼ����
		cnt++;
		if (cnt == M + 1)			//M+1,+1��ʾ���ϸ�����˳��
		{
			for (int i = 0;i < N;i++)
				cout << s[i]<<' ';				//ֱ�����
			flag = 1;
		}
	}
	for (int i = 1;i <= N;i++)
	{
		if (cnt == 0) i = s[now];				
		//�����û�е���������У����Ȼ��Ŀǰ�±��ֵ���ٰ���Ⱦɫ�����ʣ�
		if (!visit[i])
		{
			visit[i] = 1;
			s[now] = i;				//Ⱦɫ
			dfs(now + 1);
			s[now] = 0;				//����
			visit[i] = 0;
		}
	}
}
int main()
{
	cnt = 0,flag=0;
	cin >> N >> M;
	for (int i = 0;i < N;i++)
		cin >> s[i];			//ɨ������
	dfs(0);		
	
}