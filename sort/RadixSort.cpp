#include<iostream>
#include<vector>
using namespace std;

void RadixSort(vector<int> &A,int MSB){
	
	for(int i=0;i<MSB;i++){
		vector<vector<int>> T(10);
		vector<int> B;

		for(int j=0;j<A.size();j++){
			int temp=((int)(A[j]/pow(10,i)))%10;
			T[temp].push_back(A[j]);
		}
		
		for(int i=0;i<T.size();i++){
			for(int j=0;j<T[i].size();j++){
				B.push_back(T[i][j]);
			}
		}

		A.assign(begin(B),end(B));
	}

}	

int main(){
	vector<int> A;

	for(int i=1;i<=40;i++){
		int temp=rand()%9999;
		A.push_back(temp);

	}

	for(int i=0;i<A.size();i++){
		cout<<A[i]<<" ";
	}

	cout<<endl;

	RadixSort(A,4);

	for(int i=0;i<A.size();i++){
		cout<<A[i]<<" ";
	}

	return 0;
}