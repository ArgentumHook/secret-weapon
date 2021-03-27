#include<bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	cin>>str;
	set<string> ss;
	string tmp="";
	for(int i=0;i<str.length();i++)
	{
		if(str[i]==str[i+1])
		{
			tmp+=str[i];
		}
		else
		{
			tmp+=str[i];
			ss.insert(tmp);
			tmp="";
		}
	}
	for(set<string>::iterator it=ss.begin();it!=ss.end();it++)
		cout<<*it<<endl;
	return 0;
}
