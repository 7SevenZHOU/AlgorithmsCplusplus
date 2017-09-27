#include<iostream>
#include<stdlib.h>
#include<vector>
#include<list>
using namespace std;

void BucketSort(vector<float> &A){
	int n=A.size();
	vector<list<float>> L(n);
	vector<float> B;

	for(int i=0;i<n;i++){
		int temp=floor(n*A[i]);
		L[temp].push_back(A[i]);
	}

	for(int i=0;i<n;i++) L[i].sort();

	for(int i=0;i<n;i++){
		for(list<float>::iterator j=L[i].begin();j!=L[i].end();j++){
			B.push_back(*j);
		}
	}

	A.assign(begin(B),end(B));

}

int main(){
	vector<float> A;
	for(int i=1;i<=400;i++){
		A.push_back(float(rand()%1000)/1000);
	}
	for(int i=0;i<A.size();i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
	cout<<endl;

	//InsertionSort(A);
	BucketSort(A);
	for(int i=0;i<A.size();i++){
		cout<<A[i]<<" ";
	}

}