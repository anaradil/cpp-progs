#include <iostream>
#include <vector>
#include <cstdio>
#include <climits>

#define PARENT(i) ((i-1)>> 1)
#define LEFT(i) (i << 1)+1
#define RIGHT(i) (i << 1)+2
using namespace std;

int heap_size;

void maxHeapify(vector<int> &a, int i) {
	int l,r,n,max,temp;
	n = heap_size;
	while(i < n) {
		l = LEFT(i);
		r = RIGHT(i);
		if(l < n && a[l] > a[i])
			max = l;
		else 
			max = i;
		if(r < n && a[r] > a[max])
			max = r;
		if (max != i) {
			temp = a[i];
			a[i] = a[max];
			a[max] = temp;
			i = max;
		} else {
			break;
		}
	}
}

void buildMaxHeap(vector<int> &a) {
	heap_size = a.size();
	for(int i = a.size()/2-1; i >= 0; i--) {
		maxHeapify(a,i);
	}
}

int heapMaximum(vector<int> &a) {
	return a[0];
}

//complexity O(lgn)
int heapExtractMax(vector<int> &a) {
	if(heap_size > 1) { 
		int max = a[0];
		a[0] = a[heap_size-1];
		heap_size--;
		maxHeapify(a,0);
		return max;
	}
}

void heapIncreaseKey(vector<int> &a, int i, int key) {
	if(key > a[i]) {
		a[i] = key;
		while(i > 0 && a[PARENT(i)] < a[i]) {
			int temp = a[i];
			a[i] = a[PARENT(i)];
			a[PARENT(i)] = temp;
			i = PARENT(i);
		}
	}
}

void maxHeapInsert(vector<int> &a, int key) {
	heap_size++;
	a[heap_size-1] = INT_MIN;
	heapIncreaseKey(a,heap_size-1,key);
}

int main() {
	vector<int> a = {15,13,9,5,12,8,7,4,0,6,2,1};
	heap_size = a.size();
	maxHeapInsert(a,10);
	for(int i = 0; i < heap_size; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}

