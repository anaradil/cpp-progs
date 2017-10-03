#include <vector>
#include <iostream>

using namespace std;

int search(vector<int> &nums, int target) {
	if(nums.size()==0)
		return -1;
	int mid, l = 0, r = nums.size()-1;
	while(l <= r){
		mid = l + (r-l)/2;
		if(nums[mid] == target)
			return mid;
		if(nums[mid] <= nums[r]) {
			if(target > nums[mid] && target <= nums[r])
				l = mid+1;
			else
				r = mid-1;

		} else if(nums[l] <= nums[mid]) {
			if(target >= nums[l] && target < nums[mid])
				r = mid-1;
			else
				l = mid+1;
		}
	}
	return -1;
}

int main() {
	vector<int> a = {4,5,6,7,0,1,2};
	cout << search(a,1) << endl;
	return 0;
}