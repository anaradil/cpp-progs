#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int findMedian(vector<int> &a, int p, int r) {
	int center = (p+r)/2;
	if(a[center] < a[p])
		swap(a[p],a[center]);
	if(a[r] < a[p])
		swap(a[p],a[r]);
	if(a[r] < a[center])
		swap(a[center],a[r]);
	return center;
}

int medianPartition(vector<int> &a, int p, int r){
	int x = a[findMedian(a,p,r)];
	int i = p-1;
	int j = r+1;
	while(true) {
		do {
			j--;
		} while(a[j] > x);
		do {
			i++;
		} while(a[i] < x);
		if(i < j)
			swap(a[i],a[j]);
		else
			return j;
	}
}

void medianSort(vector<int> &a, int p, int r){
	if(p < r) {
		int q = medianPartition(a,p,r);

		for(int i = 0; i < a.size(); i++){
		cout << a[i] << " ";
	}
	cout << endl;
		medianSort(a,p,q);
		medianSort(a,q+1,r);
	}
}

int main() {
	vector<int> v = {6,1,4,9,0,3,5,2,7,8};
	medianSort(v,0,v.size()-1);
	for(int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	return 0;
}