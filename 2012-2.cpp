#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
	int id;
	string name;
	char sex;
	int age;
}stu;

bool cmp(stu a,stu b)
{
	return a.id<b.id;
}

int main()
{
	stu s[105];
	s[0].id=10;s[0].name="wes";s[0].sex='f';s[0].age=23;
	s[1].id=20;s[1].name="ert";s[1].sex='f';s[1].age=45;
	s[2].id=30;s[2].name="str";s[2].sex='t';s[2].age=89;
	string input;
	int n=3;
	while(cin>>input)
	{
		if(input[0]=='I')
		{
			int tmp=0;
			string p="";
			int i=1;
			while(input[i]!=',')
			{
				tmp*=10;
				tmp+=(input[i]-'0');
				i++;
			}
			s[n].id=tmp;
			tmp=0;
			i++;
			while(input[i]!=',')
			{
				p+=input[i];
				i++;
			}
			s[n].name=p;
			i++;
			s[n].sex=input[i];
			i+=2;
			while(input[i]!=','&&i<input.length())
			{
				tmp*=10;
				tmp+=(input[i]-'0');
				i++;
			}
			s[n].age=tmp;
			n++;
		}
		else
		{
			int tmp=0;
			int i=1;
			while(input[i]!=',')
			{
				tmp*=10;
				tmp+=(input[i]-'0');
				i++;
			}
			int pos=0;
			for(i=0;i<n;i++)
			{
				if(s[i].id==tmp)
				{
					pos=i;
					break;
				}
			}
			if(pos==n-1)
				n--;
			else
			{
				for(i=pos+1;i<n;i++)
					s[i-1]=s[i];
				n--;
			}
		}
		sort(s,s+n,cmp);
		for(int i=0;i<n-1;i++)
            cout<<"("<<s[i].id<<","<<s[i].name<<","<<s[i].sex<<","<<s[i].age<<"),";
        cout<<"("<<s[n-1].id<<","<<s[n-1].name<<","<<s[n-1].sex<<","<<s[n-1].age<<")"<<endl;
	}
	return 0;
}

