#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
	char data;
	node* lc;
	node* rc;
}BiNode;

BiNode* build(string mid,string post,int midSt,int midEd,int postSt,int postEd)
{
	if(midSt>midEd)
		return NULL;
	if(midSt==midEd)
	{
		BiNode* root=(BiNode*)malloc(sizeof(BiNode));
		root->data=mid[midSt];
		root->lc=NULL;
		root->rc=NULL;
		return root;
	}
	int pos=-1;
	for(int i=midSt;i<=midEd;i++)
		if(mid[i]==post[postEd])
		{
			pos=i;
			break;
		}
	BiNode* root=(BiNode*)malloc(sizeof(BiNode));
	root->data=post[postEd];
	root->lc=build(mid,post,midSt,pos-1,postSt,postSt+pos-1);
	root->rc=build(mid,post,pos+1,midEd,postSt+pos,postEd-1);
	return root;
}

void dfs(BiNode* root)
{
	if(!root)
		return;
	cout<<root->data;
	dfs(root->lc);
	dfs(root->rc);
}

int main()
{
	string mid,post;
	cin>>post>>mid;//CHBEDA CBHADE
	int len=mid.length();
	BiNode* p=build(mid,post,0,len-1,0,len-1);
	dfs(p);
	return 0;
}

