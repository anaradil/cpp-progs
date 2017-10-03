#include <vector>
#include <iostream>

using namespace std;

int partition(vector<int> &a, vector<int> &ind, int p, int r) {
	int index = p + (rand() % (int)(r - p + 1));
	int pivot = a[index];
	int i = p-1, j = r+1;
	while(true) {
		do{
			i++;
		}while(a[i] < pivot);
		do{
			j--;
		}while(a[j] > pivot);
		if(i < j) {
			swap(a[i],a[j]);
			swap(ind[i], ind[j]);
		}
		else
			return j;
	}
}

int sort(vector<int> &a, vector<int> &ind,int p, int r) {
	if(p < r) {
		int q = partition(a,ind,p,r);
		sort(a,ind,p,q);
		sort(a,ind,q+1,r);
	}
}


int main() {
	vector<int> a = {2,5,2,8,5,6,8,8};
	vector<int> ind = {0,1,2,3,4,5,6,7};
	sort(a,ind,0,a.size()-1);
	vector<vector<int>> freq;
	int count = 1;
	for(int i = 0; i < a.size(); i++) {
		if(a[i] == a[i+1])
			count++;
		else {
			vector<int> temp;
			temp.push_back(ind[i]);
			temp.push_back(count);
			freq.push_back(temp);
			count = 1;
		}

		cout << a[i] << " ";
	}
	cout << endl;
	for(int i = 0; i < a.size(); i++) {
		cout << ind[i] << " ";
	}
	cout << endl;
	maxFreq
	for(int i = 0; i < freq.size(); i++) {
		cout << freq[i][0] << " " << freq[i][1] << endl;
	}
	return 0;

}