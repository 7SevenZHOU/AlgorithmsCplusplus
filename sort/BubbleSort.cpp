#include<iostream>
#include<vector>
using namespace std;

void BubbleSort(vector<int> &A){
	for(int i=A.size()-1;i>0;i--){
		for(int j=A.size()-1;j>A.size()-1-i;j--){
			if(A[j]<A[j-1]) swap(A[j],A[j-1]);
		}
	}
}

int main(){
	vector<int> A;
	for(int i=1;i<=40;i++){
		A.push_back(rand()%2000);
	}
	for(int i=0;i<A.size();i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;

	BubbleSort(A);
	for(int i=0;i<A.size();i++){
		cout<<A[i]<<" ";
	}
}