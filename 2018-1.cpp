#include<bits/stdc++.h>
using namespace std;

bool judge(string s)
{
	int ll=s.length();
	for(int i=0;i<ll/2;i++)
		if(s[i]!=s[ll-i-1])
			return false;
	return true;
}

int main()
{
	string str;
	getline(cin,str);
	int len=str.length();
	for(int i=0;i<len;i++)
		if(isupper(str[i]))
			str[i]+=32;
	vector<string> ss;
	for(int i=0;i<len;i++)
	{
		for(int j=i+1;j<=len;j++)
		{
			if(judge(str.substr(i,j-i)))
			{
				ss.push_back(str.substr(i,j-i));
			}
		}
	}
//	for(vector<string>::iterator it=ss.begin();it!=ss.end();it++)
//		cout<<*it<<endl;
	int maxLen=0;
	int maxCnt=0;
	for(vector<string>::iterator it=ss.begin();it!=ss.end();it++)
	{
		int tmp=it->length();
		if(tmp>maxLen)
		{
			maxLen=tmp;
			maxCnt=1;
		}
		else if(tmp==maxLen)
			maxCnt++;
	}
	cout<<maxLen<<" "<<maxCnt<<endl;
	return 0;
}
