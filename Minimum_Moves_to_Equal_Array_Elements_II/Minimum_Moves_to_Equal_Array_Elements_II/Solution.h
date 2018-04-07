#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {  //优解：没想到真的是中位数。。不过优解在于排序的时候用了nth_element()，因为只需要确定中间那个位置的
	              //值，其他的元素不需要排序，而且这个函数的复杂度是O(n)，比sort()的O(nlogn)要好，所以效率高。
public:
	int minMoves2(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int mid = nums[nums.size() / 2], res = 0;
		for (int n : nums){
			res += abs(n - mid);
		}
		return res;
	}
};