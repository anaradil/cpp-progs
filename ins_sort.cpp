#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

/*
best-case = (n)
average = n^2
worst-case = O(n^2)

	{5,2,4,5,1,3}
	1 iter: key = 2; 
			5 > 2 -> {5,5,4,6,1,3}
						^
						v[j+1] = v[j]
			{2,5,4,6,1,3}
			 ^
			 v[j+1] = key
	2 iter: key = 4
			5 > 4 -> {2,5,5,6,1,3}
			{2,4,5,6,1,3}
	and so on...
*/
void sort_nondecr(vector<int> &v) {
	int i,j,key;
	for(i = 1; i < v.size(); i++) {
		key = v[i];
		j = i - 1;
		while (j >= 0 && v[j] > key) {
			v[j+1] = v[j];
			j--;
		}
		v[j+1] = key;
	} 
}

void sort_nonincr(vector<int> &v) {
	int i,j,key;
	for(i = 1; i < v.size(); i++ ){
		key = v[i];
		j = i -1;
		while(j >= 0 && v[j] < key) {
			v[j+1] = v[j];
			j--;
		}
		v[j+1] = key;
	}
}

int main() {
	vector <int> v = {5,2,4,6,1,3};
	sort_nonincr(v);

	for(vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << (*it) << " ";
	}
	return 0;
}

