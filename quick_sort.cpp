#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void swap(vector<int> &v, int i, int j){
	int temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

int partition(vector<int> &a, int p, int r) {
	if (adjacent_find(a.begin(), a.end(), not_equal_to<int>() ) == a.end() ){
    	return (p+r)/2;
	}
	int x = a[r],temp;
	int i = p-1;
	for(int j = p; j < r; j++) {
		if(a[j] <= x) {
			i++;
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}			
	}
	temp = a[i+1];
	a[i+1] = a[r];
	a[r] = temp;
	return i+1;
}

int randomPartition(vector<int> &a, int p, int r) {
	int i = rand()%r+p;
	int temp = a[r];
	a[r] = a[i];
	a[i] = temp;
	return partition(a,p,r);
}

int hoarePartition(vector<int> &a, int p, int r) {
	int x = a[p];
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

void randomQuickSort(vector<int> &a, int p, int r) {
	if(p < r) {
		int q = randomPartition(a,p,r);
		randomQuickSort(a,p,q-1);
		randomQuickSort(a,q+1,r);
	}
}

void quickSort(vector<int> &a, int p, int r) {
	if(p < r) {
		int q = hoarePartition(a,p,r);
		quickSort(a,p,q);
		quickSort(a,q+1,r);
	}
}

void tailQuickSort(vector<int> &a, int p, int r) {
	while(p < r) {
		int q = hoarePartition(a,p,r);
		tailQuickSort(a,p,q);
		p = q+1;
	}
}

int main() {
	vector<int> v = {13,19,9,5,12,8,7,4,11,2,6,21};
	randomQuickSort(v,0,v.size()-1);
	for(int i =0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	return 0;
}