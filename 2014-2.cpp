#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	vector<int> ss;
	cout<<"ÊäÈë£º"<<endl;
	bool flag=true;
	while(cin>>n)
	{
		cout<<"Êä³ö£º"<<endl;
		vector<int>::iterator pos;
		for(vector<int>::iterator it=ss.begin();it!=ss.end();it++)
			if(*it==n)
			{
				flag=false;
				pos=it;
				break;
			}
		if(!flag)
			ss.erase(pos);
		ss.push_back(n);
		if(ss.size()>3)
			ss.erase(ss.begin());
		for(vector<int>::iterator it=ss.end()-1;it>=ss.begin();it--)
			cout<<*it<<" ";
		cout<<endl;
		flag=true;
		cout<<"ÊäÈë£º"<<endl;
	}
	return 0;
}
