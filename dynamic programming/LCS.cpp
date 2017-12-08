#include<iostream>
#include<vector>
using namespace std;

tuple<vector<vector<int> >,vector<vector<string> > > LongestCommonSubsequence(const string &X,const string &Y){
    int m=X.length();
    int n=Y.length();
    vector<vector<int> > c(m+1,vector<int>(n+1,0));
    vector<vector<string> > b(m+1,vector<string>(n+1,"0"));

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(X[i-1]==Y[j-1])
            {
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]="\u2196";
                //↖
            }
            else if(c[i-1][j]>=c[i][j-1])
            {
                c[i][j]=c[i-1][j];
                b[i][j]="\u2191";
                //↑
            }
            else
            {
                c[i][j]=c[i][j-1];
                b[i][j]="\u2190";
                //←
            }
        }
    
    }
    return {c,b};

}

int main(){
    string x="ABCBDAB";
    string y="BDCABA";
    int m=x.length();
    int n=y.length();
    auto [c,b]=LongestCommonSubsequence(x,y);
    cout<<"Longest Length: "<<c[m][n]<<endl<<endl;
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;

}
