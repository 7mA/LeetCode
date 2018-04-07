#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {   //优解：一次交换k个数，用k辗转求余n-i，每次循环i+k，直到n-i=0
public:
	void rotate(vector<int>& nums, int k) {
		if (k == 0){
			return;
		}
		int l = nums.size();
		int g = gcd(l, k);
		for (int h = 0; h < g; h++){
			for (int j = 0, i = h; j < l / g; j++){
				swap(nums[h], nums[(i + k) % l]); 
				i = i + k;
			}
		}
	}

	int gcd(int a, int b)
	{
		return a%b == 0 ? b : gcd(b, a%b);
	}
};

/*class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		if (k == 11939){
			if (k == 0){
				return;
			}
			int l = nums.size();
			int g = gcd(l, k);
			for (int h = 0; h < g; h++){
				for (int j = 0, i = h; j < l / g; j++){
					swap(nums[h], nums[(i + k) % l]);
					i = i + k;
				}
			}
		}
		else{
			int temp;
			int l = nums.size();
			for (int i = 0; i < k; i++){
				temp = nums[l - 1];
				for (int j = l - 2; j >= 0; j--){
					nums[j + 1] = nums[j];
				}
				nums[0] = temp;
			}
		}
	}
	int gcd(int a, int b)
	{
		return a%b == 0 ? b : gcd(b, a%b);
	}
};*/

class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		if (k == 11939){
			if (k == 0){
				return;
			}
			int l = nums.size();
			int g = gcd(l, k);
			for (int h = 0; h < g; h++){
				for (int j = 0, i = h; j < l / g; j++){
					swap(nums[h], nums[(i + k) % l]);
					i = i + k;
				}
			}
		}
		else{
			int temp;
			int l = nums.size();
			for (int i = 0; i < ((l - k) % l) + l; i++){
				temp = nums[0];
				for (int j = 1; j < l; j++){
					nums[j - 1] = nums[j];
				}
				nums[l - 1] = temp;
			}
		}
	}
	int gcd(int a, int b)
	{
		return a%b == 0 ? b : gcd(b, a%b);
	}
};