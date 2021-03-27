#include<bits/stdc++.h>
using namespace std;
map< string,vector<string> > Q;
map< string,bool > mark;
string s1,s2;

void dfs(string k)
{
	if(k==s2)
	{
		map< string,bool >::iterator it;
		for(it=mark.begin();it!=mark.end();it++)
			if(it->second)
				cout<<">"<<it->first;
		return;
	}
	vector<string>::iterator jt;
	for(jt=Q[k].begin();jt!=Q[k].end();jt++)
	{
		string tt=*jt;
		mark[tt]=true;
		dfs(tt);
		mark[tt]=false;
	}
}

int main()
{
	cin>>s1>>s2;//(aaaa(bbbb(cccc,dddd),eeee(ffff))) ffff
	string tmp="";
	stack<string> S;
	S.push("");
	for(int i=0;i<s1.length();i++)
	{
		if(s1[i]=='(')
		{
			if(i)
			{
				Q[S.top()].push_back(tmp);
				S.push(tmp);
				tmp="";
			}
		}
		else if(s1[i]==')')
		{
			if(tmp!="")
			{
				Q[S.top()].push_back(tmp);
				S.pop();	
			}	
			tmp="";
		}
		else if(s1[i]==',')
		{
			if(tmp!="")
				Q[S.top()].push_back(tmp);
			tmp="";
		}
		else
			tmp+=s1[i];
	}
	Q.erase(Q.begin());
	string ss=Q.begin()->first;
	cout<<ss;
	dfs(ss);
	return 0;
}
