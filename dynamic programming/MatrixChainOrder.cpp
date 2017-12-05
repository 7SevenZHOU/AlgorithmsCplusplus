#include<iostream>
#include<vector>
using namespace std;

std::tuple<int,vector<vector<int> > > MatrixChainOrder(const vector<int> &p)
{
	int n=p.size()-1;
	vector<vector<int> > m(n+1,vector<int>(n+1,0));
	vector<vector<int> > s(n+1,vector<int>(n+1,0));

	for(int l=2;l<=n;l++)
	{
		for(int i=1;i<=n-l+1;i++)
		{
			int j=i+l-1;
			m[i][j]=INT_MAX;
			for(int k=i;k<=j-1;k++)
			{
				int q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(q<m[i][j])
				{
					m[i][j]=q;
					s[i][j]=k;
				}
			}
		}
	}
	return {m[1][n],s};
}

void PrintOptimalParens(const vector<vector<int> > &s,int i,int j){
	if(i==j)
		printf("A%i",i);
	else
	{
		cout<<"(";
		PrintOptimalParens(s,i,s[i][j]);
		PrintOptimalParens(s,s[i][j]+1,j);
		cout<<")";
	}
}



int main(){
	vector<vector<int> > p(6,vector<int>(2));
	srand(time(NULL));
	vector<int> a;
	vector<int> b{30,35,15,5,10,20,25};

	for(int i=0;i<7;i++)
	{
		a.push_back(rand()%50+1);
	}

	for(int i=0;i<6;i++)
	{
		p[i][0]=a[i];
		p[i][1]=a[i+1];
	}

	for(int i=0;i<6;i++)
	{
		for(int j=0;j<2;j++)
		{
			cout<<p[i][j]<<" ";
		}
		cout<<endl;
	}
	//int r1=MatrixChainOrder(a);
	//cout<<r1<<endl;
	auto [r2,s]=MatrixChainOrder(b);
	cout<<r2<<endl;
	PrintOptimalParens(s,1,6);

	return 0;
}