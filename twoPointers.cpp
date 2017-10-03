#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int findMinSum(vector<int> &a, int k) {
	int n = a.size(),sum = 0,min = 0, j = -1;
	for(int i = 0; i < n; i++) {
		cout << "i: " << a[i] << endl;
		for(j = j+1; j < n; j++) {
			cout << "j: " << a[j] << endl;
			sum+=a[j];
			cout << "sum " << sum << endl;
			if(sum > k){
				cout << "SUM " << sum << endl;
				if(j-i+1 > min)
					min = j-i+1;
				
				cout << "MIN " << min << endl;
				break;
			}
		}
		sum-=a[i];
	}
	return min;
}

int findSum(vector<int> &a, int k) {
	int min = -1;
	for(int i = 0; i < a.size(); i++) {
		int s = 0;
		for(int j = i; j < a.size(); j++) {
			s+=a[j];
			cout << "SUM " << s << endl;
			if(s > k) {
				cout << "j:" << j << endl;
				if(j-i+1 > min)
					min = j-i+1;
				break;
			}
		}
	}
	return min;
}
int main() {
	vector<int> a = {3,2,5,1,2,4,6,5,0,8};
	cout << findSum(a,7);
	return 0;
}