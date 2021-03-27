#include<bits/stdc++.h>
using namespace std;

bool judge(int n)
{
	if(n<=1)
		return false;
	for(int i=2;i<=sqrt(n);i++)
		if(n%i==0)
			return false;
	return true;
}


void dfs(map<int,int> Q,int n,int m)
{
	if(n>m)
	{
		map<int,int>::iterator it,max;
//		for(it=Q.begin();it!=Q.end();it++)
//			cout<<it->first<<" "<<it->second<<endl;
		while(!Q.empty())
		{
			max=Q.begin();
			for(it=Q.begin();it!=Q.end();it++)
			{
				if((max->second<it->second)||(max->second==it->second&&max->first>it->first))
					max=it;
			}
			if(max->second>0)
				cout<<max->first<<":"<<max->second<<" ";
			Q.erase(max);
		}
		cout<<endl;
	}
	else
	{
		for(int i=2;i<=n/2;i++)
		{
			if(judge(i)&&judge(n-i))
			{
				Q[i]++;
				Q[n-i]++;
				dfs(Q,n+2,m);
				Q[i]--;
				Q[n-i]--;
			}
		}
	}
}

int main()
{
	int n,m;
	cin>>n>>m;
	map<int,int>Q;
	Q.clear();
	if(n%2==0)
		dfs(Q,n,m);
	else 
		dfs(Q,n+1,m);
	return 0;
}
