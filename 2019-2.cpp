#include<bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	cin>>str;
	vector<int>num;
	int tmp=0;
	for(int i=0;i<=str.length();i++)
	{
		if(isdigit(str[i]))
		{
			tmp*=10;
			tmp+=(str[i]-'0');	
		}
		else
		{
			num.push_back(tmp);
			tmp=0;
		}
	}
//	for(vector<int>::iterator it=num.begin();it!=num.end();it++)
//		cout<<*it<<endl;
	sort(num.begin(),num.end());
	int len=num.size();
	int sum=0;
	for(int i=1;i<len;i++)
	{
		num[i]+=num[i-1];
		sum+=num[i];
		sort(num.begin()+i,num.end());
	}
	cout<<sum<<endl;
	return 0;
}
