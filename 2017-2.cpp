#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[105];
	cout<<"请输入数组"<<endl;
	string str;
	getline(cin,str);
	int tmp=0;
	bool isNega=false;
	int len=0;
	for(int i=0;i<=str.length();i++)
	{
		if(str[i]=='-')
			isNega=true;
		else if(str[i]==' '||str[i]=='\0')
		{
			if(isNega)
				tmp*=(-1);
			a[len++]=tmp;
			tmp=0;
			isNega=false;
		}
		else
		{
			tmp*=10;
			tmp+=(str[i]-'0');
		}
	}
//	for(int i=0;i<len;i++)
//		cout<<a[i]<<" ";
	cout<<"请输入要查找的元素"<<endl;
	cin>>tmp;
	int low=0,high=len-1;
	int cnt=1;
	while(low<=high)
	{
		int mid=(low+high)/2;
		if(a[mid]==tmp)
		{
			cout<<"查找成功 "<<"比较次数为："<<cnt<<endl;
			return 0;
		}
		else if(a[mid]<tmp)
		{
			low=mid+1;
			cnt++;
		}
		else
		{
			high=mid-1;
			cnt++;
		}
	}
	if(a[low]!=tmp)
		cout<<"查找失败 "<<"比较次数为："<<cnt-1<<endl;
	else
		cout<<"查找成功 "<<"比较次数为："<<cnt<<endl;
	return 0;
}
