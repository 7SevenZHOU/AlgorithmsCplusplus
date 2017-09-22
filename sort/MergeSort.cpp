#include<iostream>
#include<vector>
#include<stdlib.h>

using namespace std;

void Merge(vector<int> &A,int low,int high,int mid){
	vector<int> temp=A;
	int l=low;
	int h=high;
	int m=mid+1;
	while(l<=mid && m<=high){
		if(temp[l]<=temp[m]){
			A[low]=temp[l];
			l++;
		}
		else{
			A[low]=temp[m];
			m++;
		}
		low++;
	}

	while(l<=mid){
		A[low]=temp[l];
		l++;
		low++;

	}

	while(m<=high){
		A[low]=temp[m];
		m++;
		low++;

	}



}

void MergeSort(vector<int> &A,int begin_,int end_){
	if(begin_<end_){
		int m=(begin_+end_)/2;
		MergeSort(A,begin_,m);
		MergeSort(A,m+1,end_);
		Merge(A,begin_,end_,m);
	}


}


int main(){
	std::vector<int> A;
	for(int i=0;i<21;i++){
		A.push_back(rand()%2000);
	}

	for(int i=0;i<A.size();i++) cout<<A[i]<<" ";
	cout<<endl;

	MergeSort(A,0,20);
	
	for(int i=0;i<A.size();i++) cout<<A[i]<<endl;

	return 0;
}
