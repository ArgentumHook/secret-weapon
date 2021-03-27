#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
	string name;
	int sc1,sc2,sc3;
	int sum;
}stu;

bool cmp(stu a,stu b)
{
	if(a.sum!=b.sum)
		return a.sum>b.sum;
	return a.name<b.name;
}

int main()
{
	int n;
	stu s[105];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s[i].name>>s[i].sc1>>s[i].sc2>>s[i].sc3;
		s[i].sum=s[i].sc1+s[i].sc2+s[i].sc3;
	}
	for(int i=0;i<n;i++)
	{
		if(s[i].sc1<60||s[i].sc2<60||s[i].sc3<60)
			cout<<"*name:"<<s[i].name<<" score:"<<s[i].sc1<<" "<<s[i].sc2<<" "<<s[i].sc3<<endl;
	}
	sort(s,s+n,cmp);
	for(int i=0;i<n;i++)
	{
		cout<<"["<<i+1<<"]"<<"name:"<<s[i].name<<" score:"<<s[i].sc1<<" "<<s[i].sc2<<" "<<s[i].sc3<<endl;
	}
	return 0;
}
