#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s1,s2;
	cin>>s1>>s2;
	int len1=s1.length();
	int len2=s2.length();
	int maxLen=0;
	int maxCnt=0;
	for(int i=0;i<len1;i++)
	{
		int tmp=0;
		for(int j=0;j<len2;j++)
		{
			if(s1[i]==s2[j])
			{
				tmp++;
				if(tmp>maxLen)
				{
					maxLen=tmp;
					maxCnt=1;
				}
				else if(tmp==maxLen)
					maxCnt++;
				for(int p=i+1,q=j+1;p<len1&&q<len2;)
				{
					if(s1[p]==s2[q])
					{
						tmp++;
						if(tmp>maxLen)
						{
							maxLen=tmp;
							maxCnt=1;
						}
						else if(tmp==maxLen)
							maxCnt++;
						p++;
						q++;
					}
					else
					{
						tmp=0;
						break;
					}
				}
				tmp=0;
			}
		}
	}
	cout<<maxLen<<" "<<maxCnt<<endl;
	return 0;
}
