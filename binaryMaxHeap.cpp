#include <cstdio>
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

#define PARENT(i) (i >> 1)
#define LEFT(i) (i << 1)
#define RIGHT(i) (i << 1)+1

class BinaryMaxHeap {
		long int heapSize;
		vector<long int> arr;
	public:
		BinaryMaxHeap(vector<long int>&);
		void maxHeapify(int);
		void buildMaxHeap();
		void heapSort();
		void printHeap(int);
};

BinaryMaxHeap::BinaryMaxHeap(vector<long int> &a){
	arr.push_back(0);
	arr.insert(arr.begin()+1, a.begin(), a.end());
	heapSize = a.size();
}

void BinaryMaxHeap::maxHeapify(int i) {
	long int l,r,max;
	l = LEFT(i);
	r = RIGHT(i);
	if(l <= heapSize && arr[l] > arr[i])
		max = l;
	else
		max = i;
	if(r <= heapSize && arr[r] > arr[max])
		max = r;
	if(max != i) {
		long int temp = arr[max];
		arr[max] = arr[i];
		arr[i] = temp;
		BinaryMaxHeap::maxHeapify(max);
	}
}

void BinaryMaxHeap::buildMaxHeap() {
	heapSize = arr.size()-1;
	for(int i = heapSize/2; i > 0; i--) {
		maxHeapify(i);
	}
}

void BinaryMaxHeap::heapSort() {
	BinaryMaxHeap::buildMaxHeap();
	int n = heapSize;
	for(int i = n; i > 1; i--) {
		long int temp = arr[1];
		arr[1] = arr[i];
		arr[i] = temp;
		heapSize--;
		maxHeapify(1);
	}
	BinaryMaxHeap::printHeap(n);
}

void BinaryMaxHeap::printHeap(int n) {
	for(int i = 1; i <= n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int n;
	long int temp;
	vector<long int> v;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	BinaryMaxHeap heap(v);
	heap.heapSort();
	return 0;
}

