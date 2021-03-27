#include<bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	getline(cin,str);
	int len=str.length();
	int tmp=0;
	int max=0;
	for(int i=0;i<len;i++)
	{
		if(str[i]=='(')
		{
			tmp++;
			if(tmp>max)
				max=tmp;
		}
		else if(str[i]==')')
			tmp--;
	}
	cout<<max<<endl;
	return 0;
}
