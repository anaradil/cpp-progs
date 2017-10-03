#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ret
{
	int w;
	int x;
	int y;
	int z;
};

ret fuzzyPartition(vector<vector<int>> &a, int p, int r) {
	ret temp;
	int pivot = p + (rand() % (int)(r - p + 1));
	cout << "pivot: " << pivot << endl;
	swap(a[pivot],a[r]);
	int left = a[r][0], right = a[r][1];
	cout << "left: " << left << endl;
	cout << "right: " << right << endl;
	int i = p - 1;
	for(int j = p; j < r; j++){
		if(a[j][0] <= left) {
			i++;
			swap(a[i],a[j]);
		}
	}
	swap(a[i+1],a[r]);
	for(int i = 0; i < a.size(); i++){
		cout << "{" << a[i][0] << "," << a[i][1] <<  "}" << " ";
	}
	cout << endl;
	//from p to y - strictly less
	temp.y = i + 1;
	cout << "y " << temp.y << endl;
	i = p - 1;
	cout << "i " << i << endl;
	for(int j = p; j < temp.y; j++){
		if(a[j][1] < left){
			i++;
			swap(a[i],a[j]);
		}
	}
	for(int i = 0; i < a.size(); i++){
		cout << "{" << a[i][0] << "," << a[i][1] <<  "}" << " ";
	}
	cout << endl;
	cout << "i " << i << endl;
	//from w to y - overlap the left side
	temp.w = i + 1;
	i = r + 1;
	for(int j = r; j > temp.y; j--){
		if(a[j][1] >= right) {
			cout << "YEs " << endl;
			i--;
			swap(a[i],a[j]);
		}
	}
	for(int i = 0; i < a.size(); i++){
		cout << "{" << a[i][0] << "," << a[i][1] <<  "}" << " ";
	}
	cout << endl;

	cout << "r " << r << endl;
	cout << "i " << i << endl;
	temp.z = i + 1;
	cout << "z " << temp.z << endl;
	//from w to z within the pivot
	// right to z - strictly greater
	int max = a[temp.y][0];
	int max_index;
	for(int j = temp.y+1; j <= temp.z; j++){
		if(a[j][0] > max) {
			max = a[j][0];
			max_index = j;
		}
	}
	swap(a[max_index],a[temp.z]);
	i = temp.y;
	for(int j = temp.y+1; j < temp.z; j++) {
		if(a[j][1] < a[temp.z][0]){
			i++;
			swap(a[i],a[j]);
		}
	}
	temp.x = i + 1;
    return temp;

}

void fuzzySort(vector<vector<int>> &a, int p, int r) {
	if(p < r) {
		ret val = fuzzyPartition(a,p,r);
		fuzzySort(a,p,val.w);
		fuzzySort(a,val.y+1,val.x);
		fuzzySort(a,val.z,r);
	}
}

int main() {
	vector<vector<int>> v = {{3,4},{5,9},{2,4},{2,10},{1,2},{7,8},{4,6}};
	fuzzyPartition(v,0,v.size()-1);
	for(int i = 0; i < v.size(); i++){
		cout << "{" << v[i][0] << "," << v[i][1] <<  "}" << " ";
	}
	cout << endl;
	return 0;
}