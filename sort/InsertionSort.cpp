#include<iostream>
#include<vector>
using namespace std;

void InsertionSort(vector<int> &A){
	for(int i=1;i<A.size();i++){
		int j=i-1;
		int temp=A[i];
		while(j>=0 && A[i]<A[j]) j--;
		for(int k=i;k>j+1;k--){
			A[k]=A[k-1];
		}
		A[j+1]=temp;
	}
}

int main(){
	vector<int> A;
	for(int i=1;i<=40;i++){
		A.push_back(rand()%100);
	}
	for(int i=0;i<A.size();i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;


	InsertionSort(A);
	for(int i=0;i<A.size();i++){
		cout<<A[i]<<" ";
	}


}