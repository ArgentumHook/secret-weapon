#include<bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	cin>>str;
	string num="";
	vector<string> sset;
	for(int i=0;i<=str.length();i++)
	{
		if(str[i]=='+'||str[i]=='-')
		{
			if(num!="")
				sset.push_back(num);
			num="";
			if(isdigit(str[i+1]))
			{
				num+=str[i];
			}
		}
		else if(isdigit(str[i]))
		{
			num+=str[i];
		}
		else if(str[i]=='.')
		{
			if(isdigit(str[i-1])&&isdigit(str[i+1]))
				num+=str[i];
		}
		else
		{
			if(num!="")
				sset.push_back(num);
			num="";
		}	
	}
	for(vector<string>::iterator it=sset.begin();it!=sset.end();it++)
	{
		num=*it;
		bool isZero=true;
		for(int i=0;i<num.length();i++)
			if(num[i]!='0'&&num[i]!='.')
			{
				isZero=false;
				break;
			}
		if(isZero)
			num="0";
		else
		{
			int j=0,k=0;
			if(num[0]=='+'||num[0]=='-')
				j=1;
			for(int i=j;i<num.length();i++)
				if(num[i]!='0')
				{
					k=i;
					break;
				}
			num.erase(num.begin()+j,num.begin()+k);
		}
		bool isFloat=false;
		int pos=0;
		for(int i=0;i<num.length();i++)
			if(num[i]=='.')
			{
				isFloat=true;
				pos=i+1;
				break;
			}
		if(isFloat&&!isZero)
		{
			int k=0;
			for(int i=num.length()-1;i>=pos;i--)
			{
				if(num[i]!='0')
				{
					k=i+1;
					break;
				}
			}
			num.erase(num.begin()+k,num.end());
		}
		*it=num;
	}
	
	for(vector<string>::iterator it=sset.begin();it!=sset.end();it++)
		cout<<*it<<endl;
	return 0;
}
