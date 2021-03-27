#include<bits/stdc++.h>
using namespace std;

int main()
{
	string id;
	int w[]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	cin>>id;
	int len=id.length();
	int sum=0;
	for(int i=0;i<17;i++)
		sum+=(id[i]-'0')*w[i];
	int y=sum%11;
	char check[]={'1','0','X','9','8','7','6','5','4','3','2'};
	if(check[y]==id[len-1])
		cout<<id<<" "<<"ÕýÈ·"<<endl;
	else
	{
		id[len-1]=check[y];
		cout<<id<<endl;
	}
	return 0;
}
