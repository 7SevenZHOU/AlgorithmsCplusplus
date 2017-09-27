#include<iostream>
#include<vector>
using namespace std;

void SelectionSort(vector<int> &A){
	for(int i=0;i<A.size()-1;i++){
		int pos=i;
		int temp=A[i];
		for(int j=i;j<A.size()-1;j++){
			if(temp>A[j+1]){
				temp=A[j+1];
				pos=j+1;
			}
		}
		swap(A[i],A[pos]);
	}
}

int main(){
	vector<int> A;
	for(int i=1;i<=40;i++){
		A.push_back(rand()%1000);
	}
	for(int i=0;i<A.size();i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;

	SelectionSort(A);
	for(int i=0;i<A.size();i++){
		cout<<A[i]<<" ";
	}
}