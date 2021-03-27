#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
	string name;
	vector<int> gr;
	int cnt;
}stu;

bool cmp(stu a,stu b)
{
	return a.cnt>b.cnt;
}

int main()
{
	string s1,s2;
	stu s[105];
	for(int i=0;i<105;i++)
		s[i].cnt=0;
	int len=0;
	while(cin>>s1)
	{
		getline(cin,s2);
		s[len].name=s1;
		int tmp=0;
		for(int i=1;i<=s2.length();i++)
		{
			if(s2[i]==' '||s2[i]=='\0')
			{
				s[len].gr.push_back(tmp);
				if(tmp<60)
					s[len].cnt++;
				tmp=0;
			}
			else
			{
				tmp*=10;
				tmp+=(s2[i]-'0');
			}
		}
		len++;
	}
	bool flag=true;
	for(int i=0;i<len;i++)
	{
//		cout<<s[i].name<<" ";
//		for(vector<int>::iterator it=s[i].gr.begin();it!=s[i].gr.end();it++)
//			cout<<*it<<" ";
//		cout<<" ";
//		cout<<s[i].cnt<<endl;
		if(s[i].cnt>2)
		{
			flag=false;
			cout<<s[i].name<<" ";
		}	
	}
	if(flag)
		cout<<"没有不及格科目数大于2的学生";
	else
	{
		for(int i=0;i<len;i++)
		{
			if(s[i].cnt>2)
				cout<<s[i].name<<" ";
		}
	}
	cout<<endl;
	sort(s,s+len,cmp);
	for(int i=0;i<len;i++)
		cout<<s[i].name<<"的不及格科目数为"<<s[i].cnt<<endl;
	return 0;
}
