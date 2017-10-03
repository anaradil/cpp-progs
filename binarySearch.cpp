#include <vector>
#include <iostream>

using namespace std;

int binSearch(vector<int> &a, int v) {
	int x,l,r;
	l = 0;
	r = a.size()-1;
	while(true) {
		x = l + (r-l)/2;
		if(v < a[x])
			r = x-1;
		else
			l = x+1;
		cout << "left: " << l << ", right: " << r << ", mid: " << x << endl;
		if(v==a[x] || l > r)
			break;
	}
	if(v == a[x])
		return x;
	else
		return -1;
}
//interpolation Search
int interSearch(vector<int> &a, int v) {
	int x,l,r;
	l = 0;
	r = a.size()-1;
	while(true) {
		x = l + (v - a[l]) * (r-l) / (a[r] - a[l]);
		if(v < a[x])
			r = x-1;
		else
			l = x+1;
		cout << "left: " << l << ", right: " << r << ", mid: " << x << endl;
		if(v==a[x] || l > r)
			break;
	}
	if(v == a[x])
		return x;
	else
		return -1;
}


int main() {
	vector<int> v = {1,2,3,4,5,6,7,8,9,10,11,12};
	cout << interSearch(v,2) << endl;
	return 0;
}