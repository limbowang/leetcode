#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		vector<int> ret;
		int size = numbers.size();
		for (int i = 0; i < size; ++i) {
			for (int j = i + 1; j < size; j++) 
				if (numbers[j] + numbers[i] == target) {
					ret.push_back(i + 1);
					ret.push_back(j + 1);
					return ret;
				}
			}
		return ret;
	}
};

int main() {
	Solution sol;
	int in[] = {150,24,79,50,88,345,3};
	vector<int> vec;
	vector<int> ret;
	for (int i = 0; i < 7; i++) {
		vec.push_back(in[i]);
	}
	ret = sol.twoSum(vec, 200);
	cout << ret[0] << ret[1];
}
