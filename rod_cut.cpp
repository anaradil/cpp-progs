#include <cstdio>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int recursive_top_down(vector<int> &p, int n) {
	if(n == 0) 
		return 0;
	int q = INT_MIN;
	for(int i = 0; i < n; i++) {
		q = max(q, p[i] + recursive_top_down(p, n-i-1));
	}
	return q;
}

int memoized_top_down_aux(vector<int> &p, int n, vector<int> &r) {
	int q;
	if(r[n-1] >= 0)
		return r[n-1];
	if(n == 0)
		q = 0;
	else  {
		q = INT_MIN;
		for(int i = 0; i < n; i++) {
			q = max(q, p[i] + memoized_top_down_aux(p, n-i-1, r));
		}
	}
	r[n-1] = q;
	return q;
}

int memoized_top_down(vector<int> &p, int n) {
	vector<int> r(n);
	for(int i = 0; i < n; i++) {
		r[i] = INT_MIN;
	}
	return memoized_top_down_aux(p,n,r);
}

int bottom_up(vector<int> &p, int n) {
	vector<int> r(n+1);
	r[0] = 0;
	for(int j = 1; j <= n; j++) {
		int q = INT_MIN;
		for(int i = 0; i < j; i++) {
			q = max(q, p[i] + r[j-i-1]);
		}
		r[j] = q;
	}
	for(int i = 0; i <= n; i++) {
		cout << r[i] << " ";
	}
	cout << endl;
	return r[n];
}
int extended_bottom_up(vector<int> &p, int n) {
	vector<int> r(n+1);
	vector<int> s(n+1);
	r[0] = 0;
	for(int j = 1; j <= n; j++) {
		int q = INT_MIN;
		for(int i = 0; i < j; i++) {
			if(q < p[i] + r[j-i-1]) {
				q = p[i] + r[j-i-1];
				s[j] = i+1;
			}
		}
		r[j] = q;
	}
	for(int i = 0; i <= n; i++) {
		cout << r[i] << " ";
	}
	cout << endl;
	for(int i = 0; i <= n; i++) {
		cout << s[i] << " ";
	}
	cout << endl;
	int res = r[n];
	while(n > 0) {
		cout << s[n] << endl;
		n = n - s[n];
	}
	return res;
}

int main() {
	vector<int> price = {1,5,8,9,10,17,17,20,24,30};
	cout << extended_bottom_up(price, 4) << endl;
	return 0;
}