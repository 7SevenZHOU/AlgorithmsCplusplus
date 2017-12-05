#include<iostream>
#include<vector>
using namespace std;
int BottomUpCutRod(const vector<int> &p,int n){
	vector<int> r(n+1,0);
	r[0]=0;
	for(int j=1;j<=n;j++)
	{
		int q=INT_MIN;
		int t=min(j,(int)p.size()-1);
		for(int i=1;i<=t;i++)
		{
			q=max(p[i]+r[j-i],q);
		}
		r[j]=q;
	}
	return r[n];
}

int ExtendedBottomUpCutRod(const vector<int> &p,int n,vector<int> &s){
	vector<int> r(n+1,0);
	r[0]=0;
	for(int j=1;j<=n;j++)
	{
		int q=INT_MIN;
		int t=min(j,(int)p.size()-1);
		for(int i=1;i<=t;i++)
		{
			if(q<p[i]+r[j-i])
			{
				q=p[i]+r[j-i];
				s[j]=i;
			}
			r[j]=q;
		}
	}
	return r[n];
}

void PrintCutRodSolution(const vector<int> &s,int n){
	while(n>0)
	{
		cout<<s[n]<<endl;
		n=n-s[n];
	}
}

int main(){
	int a[]={0,1,5,8,9,10,17,17,20,24,30};
	vector<int> p(a,a+11);
	
	int n;
	cout<<"please input length n!"<<endl;
	cin>>n;
	cout<<endl;
	vector<int> s(n+1,0);
	int r=ExtendedBottomUpCutRod(p,n,s);
	PrintCutRodSolution(s,n);
	/*
	for(int i=0;i<s.size();i++)
	{
		cout<<s[i]<<" ";

	}
	*/
	cout<<endl<<r<<endl;
	return 0;
}