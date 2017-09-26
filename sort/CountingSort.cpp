#include<iostream>
#include<vector>
using namespace std;

void CountingSort(vector<int> &A,int max_){
	vector<int> B(max_+1,0);
	vector<int> C(A.size(),0);

	for(int i=0;i<A.size();i++){
		B[A[i]]++;
	}

	for(int i=1;i<B.size();i++){
		B[i]=B[i]+B[i-1];
	}

	for(int i=0;i<A.size();i++){
		C[B[A[i]]]=A[i];
		B[A[i]]--;
	}

	A.assign(begin(C),end(C));


}

int main(){
	
	vector<int> A;
	for(int i=1;i<=50;i++){
		int temp=rand()%10;
		A.push_back(temp);
	}

	for(int i=0;i<A.size();i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;

	CountingSort(A,10);

	for(int i=0;i<A.size();i++){
		cout<<A[i]<<" ";
	}

	return 0;
}