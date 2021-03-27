#include<bits/stdc++.h>
using namespace std;

typedef struct Node
{
	string key;
	struct Node * left;
	struct Node * right;
}Node;

int search(string a,int begin,int end)
{
	int tag=-1;
	int isInBrackets=0;
	if(a[begin]=='('&&a[end]==')')
	{
		begin++;
		end--;
	}
	int flag=0;
	for(int i=begin;i<=end;i++)
	{
		if(a[i]=='(')
			isInBrackets++;
		if(a[i]==')')
			isInBrackets--;
		if((a[i]=='+'||a[i]=='-')&&isInBrackets==0)
		{
			tag=i;
			flag=1;
		}
		if((a[i]=='*'||a[i]=='/')&&isInBrackets==0&&flag==0)
			tag=i;
	}
	return tag;
}

Node* build(string a,int begin,int end)
{
	Node* p=NULL;
	if(begin>end)
		return NULL;
	if(begin==end)
	{
		p=new Node;
		p->key=a[begin];
		p->left=NULL;
		p->right=NULL;
	}
	else
	{
		int tag=search(a,begin,end);
		if(tag==-1)
		{
			int c1,c2;
			for(c1=begin;c1<=end;c1++)
				if(a[c1]!='(')
					break;
			for(c2=end;c2>=begin;c2--)
				if(a[c2]!=')')
					break;
			p=new Node;
			p->key=a.substr(c1,c2-c1+1);
			p->left=build(a,begin,c1-1);
			p->right=build(a,c2+1,end);
		}
		else
		{
			p=new Node;
			p->key=a[tag];
			if(a[begin]=='('&&a[end]==')')
			{
				begin++;
				end--;
			}
			p->left=build(a,begin,tag-1);
			p->right=build(a,tag+1,end);
		}
	}
	return p;
}

void dfs(Node* head)
{
	if(!head)
		return;
	dfs(head->left);
	dfs(head->right);
	cout<<head->key;
}

double calc(Node* root)
{
	if(root->key=="+")
		return calc(root->left)+calc(root->right);
	else if(root->key=="-")
		return calc(root->left)-calc(root->right);
	else if(root->key=="*")
		return calc(root->left)*calc(root->right);
	else if(root->key=="/")
		return calc(root->left)/calc(root->right);
	else
		return atof(root->key.c_str());
}

int main()
{
	string input;//1+(2+3)*2.4+2/4
	cin>>input;
	int length=input.length();
	Node* head=build(input,0,length-1);
	dfs(head);
	cout<<endl<<calc(head)<<endl;
	return 0;
}
