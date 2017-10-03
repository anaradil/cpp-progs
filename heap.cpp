#include <iostream>
#include <vector>
#include <cstdio>

#define PARENT(i) ((i-1)>> 1)
#define LEFT(i) (i << 1)+1
#define RIGHT(i) (i << 1)+2
using namespace std;

int heap_size;

//complexity - O(lgn)
void minHeapify(vector<int> &a, int i) {
	int l,r,n,min,temp;
	n = heap_size;
	l = LEFT(i);
	r = RIGHT(i);
	if(l < n && a[l] < a[i])
		min = l;
	else
		min = i;
	if(r < n && a[r] < a[min])
		min = r;
	if(min != i) {
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;
		minHeapify(a, min);
	}
}

void buildMinHeap(vector<int> &a) {
	heap_size = a.size();
	for(int i = a.size()/2-1; i >= 0; i--) {
		minHeapify(a,i);
	}
}


//complexity - O(lgn)
/*void maxHeapify(vector<int> &a, int i) {
	int l,r,n,max,temp;
	n = heap_size;
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
		maxHeapify(a, max);
	}
}*/

//iterative 
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
//complexity - O(n)
void buildMaxHeap(vector<int> &a) {
	heap_size = a.size();
	for(int i = a.size()/2-1; i >= 0; i--) {
		maxHeapify(a,i);
	}
}
//complexity - O(nlgn)
void heapSort(vector<int> &a) {
	buildMinHeap(a);
	for(int i = a.size()-1; i > 0; i--) {
		int temp = a[0];
		a[0] = a[i];
		a[i] = temp;
		heap_size--;
		minHeapify(a,0);
	}
}


int main() {
	vector<int> a = {5,13,2,25,7,17,20,8,4};
	heap_size = a.size();
	heapSort(a);
	for(int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	} 
	cout << endl;
	return 0;
}