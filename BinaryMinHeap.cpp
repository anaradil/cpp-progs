#include <cstdio>
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

#define PARENT(i) (i >> 1)
#define LEFT(i) (i << 1)
#define RIGHT(i) (i << 1)+1

class BinaryMinHeap {
		long int heapSize;
		vector<long int> arr;
	public:
		BinaryMinHeap();
		BinaryMinHeap(vector<long int>&);
		long int heapMin() {return arr[1];};
		void minHeapify(long int);
		void buildMinHeap();
		long int extractMin();
		void decreaseKey(long int, long int);
		void insert(long int);
		void deleteKey(long int);
		void heapSort();
		void printHeap();
		void printHeap(int);
};

BinaryMinHeap::BinaryMinHeap() {
	heapSize = 0;
	arr.push_back(0);
}

BinaryMinHeap::BinaryMinHeap(vector<long int> &a) {
	arr.push_back(0);
	arr.insert(arr.begin()+1, a.begin(), a.end());
	heapSize = a.size();
}


void BinaryMinHeap::minHeapify(long int i) {
	long int min,l,r,temp;
	l = LEFT(i);
	r = RIGHT(i);
	if(l <= heapSize && arr[l] < arr[i])
		min = l;
	else
		min = i;
	if(r <= heapSize && arr[r] < arr[min])
		min = r;
	if(min != i) {
		temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
		BinaryMinHeap::minHeapify(min);
	}
}

void BinaryMinHeap::buildMinHeap() {
	for(long int i = heapSize/2; i > 0; i--) {
		minHeapify(i);
	}
}

long int BinaryMinHeap::extractMin() {
	if(heapSize > 0) {
		long int min = arr[1];
		arr[1] = arr[heapSize];
		arr[heapSize] = LONG_MAX;
		heapSize--;
		minHeapify(1);
		return min;
	}
}

void BinaryMinHeap::decreaseKey(long int i, long int key) {
	if(key < arr[i]) {
		arr[i] = key;
		while(i > 1 && arr[PARENT(i)] > arr[i]) {
			long int temp = arr[i];
			arr[i] = arr[PARENT(i)];
			arr[PARENT(i)] = temp;
			i = PARENT(i);
		}
	}
}

void BinaryMinHeap::insert(long int key) {
	heapSize++;
	arr.push_back(LONG_MAX);
	decreaseKey(heapSize,key);
	
}

void BinaryMinHeap::deleteKey(long int key) {
	long int index;
	for(long int i = 1; i <= heapSize; i++) {
		if(arr[i] == key)
			index = i;
	}
	decreaseKey(index,LONG_MIN);
	extractMin();
}

void BinaryMinHeap::printHeap() {
	for(long int i = 1; i <= heapSize; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

void BinaryMinHeap::printHeap(int n) {
	for(long int i = 1; i <= n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}


void BinaryMinHeap::heapSort() {
	BinaryMinHeap::buildMinHeap();
	BinaryMinHeap::printHeap();
	int n = heapSize;
	cout << n << endl;
	for(int i = n; i > 1; i--) {
		long int temp = arr[1];
		arr[1] = arr[i];
		arr[i] = temp;
		heapSize--;
		minHeapify(1);
	}
	BinaryMinHeap::printHeap(n);
}
int main() {
	vector<long int> a = {1,2,3,4,5};
	BinaryMinHeap heap(a);
	heap.heapSort();
	
	
	return 0;
}