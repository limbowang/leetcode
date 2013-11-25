#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        sort(S.begin(), S.end());
		int size = S.size();
		vector<vector<int> > ret;
		for (int i = 0; i < size; i++) {
			int retSize = ret.size();
			vector<int> vec;
			vec.push_back(S[i]);
			ret.push_back(vec);
			for(int j = 0; j < retSize; j++) {
				vector<int> vec = ret[j];
				vec.push_back(S[i]);
				ret.push_back(vec);
			}
		}
		vector<int> vec;
		ret.push_back(vec);
		return ret;
    }
};

int main() {
	vector<int> vec;
	Solution sol;
	
	for (int i = 1; i < 4; i++) {
		vec.push_back(i);
	}
	vector<vector<int> > ret = sol.subsets(vec);
	for (int i = 0; i < ret.size(); i++) {
		for (int k = 0; k < ret[i].size(); k++) {
			cout << ret[i][k] << " ";
		}
		cout << endl;
	}
}
