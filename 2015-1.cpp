#include<bits/stdc++.h>
using namespace std;

int n;
string tmp="";
int cnt=0;
bool first=true;

void dfs(int k)
{
	if(k==n)
	{
		if(first)
		{
			cout<<tmp;
			first=false;	
		}
		else
			cout<<","<<tmp;
		cnt++;
		return;
	}
	for(char ch='a';ch<='c';ch++)
	{
		tmp+=ch;
		dfs(k+1);
		tmp.erase(tmp.end()-1);
	}
}

int main()
{
	cin>>n;
	dfs(0);
	cout<<" "<<cnt<<endl;
	return 0;
}
