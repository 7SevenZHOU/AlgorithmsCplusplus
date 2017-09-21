#include<iostream>
#include<vector>
using namespace std;

void Max_Heapify(vector<int> &A,  const int &pos) {
	int Left = 2 * pos + 1;
	int Right = 2 * pos + 2;
	int Len = A.size();
	int largest=pos;

	if (Left<Len) {
		if(A[pos]<A[Left]) largest = Left;
	}
	

	if (Right<Len) {
		if(A[largest]<A[Right]) largest = Right;
	}

	if (largest != pos) {
		swap(A[pos], A[largest]);
		Max_Heapify(A, largest);
	}


}

void Build_Max_Heap(vector<int> &A) {

	for (int i =A.size()/2 - 1; i >= 0; i--) {
		Max_Heapify(A, i);
	}

}

void HeapSort(vector<int> &A) {
	vector<int> temp;
	Build_Max_Heap(A);
	for (int i = A.size()-1; i > 0; i--) {
		swap(A[0], A[i]);
		temp.push_back(A[i]);
		A.pop_back();
		Max_Heapify(A, 0);

	}
	temp.push_back(A[0]);
	A = temp;
}

int main() {
	
	std::vector<int> A;
	A = { 1,3,2,5,4,6,7,11,12,-5,32,0,19,-9,-19,20};
	HeapSort(A);
	for (int i = 0; i<A.size(); i++) {
		std::cout << A[i] << endl;
	}
	system("pause");

	return 0;

}