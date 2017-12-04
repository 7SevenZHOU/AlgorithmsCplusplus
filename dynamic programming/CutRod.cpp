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

int main(){
	int a[]={0,1,5,8,9,10,17,17,20,24,30};
	vector<int> p(a,a+11);
	int r=BottomUpCutRod(p,8);
	cout<<r<<endl;
	return 0;
}