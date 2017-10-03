#include <vector>
#include <iostream>

using namespace std;

void countSort(vector<int> &a, vector<int> &b, int k) {
	vector<int> c(k+1,0);
	for(int j = 0; j < a.size(); j++) {
		c[a[j]]++;
	}

	for(int i = 1; i < c.size(); i++) {
		c[i] = c[i] + c[i-1];
	}


	for(int j = a.size()-1; j > -1; j--) {
		b[c[a[j]]-1] = a[j];
		c[a[j]]--;
	}

}


int main() {
	vector<int> a = {2,5,3,0,2,3,0,3};
	vector<int> b(a.size());
	countSort(a,b,5);
	for(int i = 0; i < b.size(); i++){
		cout << b[i] << " ";
	}
	cout << endl;
	return 0;
}