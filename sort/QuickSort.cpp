#include<iostream>
#include<vector>
using namespace std;

int Partition(vector<int> &A,int begin_,int end_){
	int x=A[end_];
	int k=begin_-1;
	for(int i=begin_;i<end_;i++){
		if(A[i]<=x){
			k=k+1;
			if(i!=k) swap(A[i],A[k]);

		}

	}
	swap(A[end_],A[k+1]);
	return k+1;
}

void QuickSort(vector<int> &A,int b,int e){
	if(b<e){
		int p=Partition(A,b,e);
		QuickSort(A,b,p-1);
		QuickSort(A,p+1,e);

	}
}

int main(){
	//int a[]={1,3,2,4,7,8,0,1,-2,-3,-4,-5,12,20,-20,-21,100,200,1,3,2,4,5};

	vector<int> A;
	for(int i=0;i<30;i++){
		A.push_back(-1000+rand()%2000);
	}
	for(int i=0;i<A.size();i++){
		cout<<A[i]<<endl;

	}

	cout<<endl<<endl;
	

	QuickSort(A,0,A.size()-1);
	for(int i=0;i<A.size();i++){
		cout<<A[i]<<endl;

	}
	return 0;

}