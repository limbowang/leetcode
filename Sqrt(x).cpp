#include <iostream>

using namespace std;

class Solution {
public:
    int sqrt(int x) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (x < 0) {
        	return -1;
        } else if (x == 0) {
        	return 0;
        } else {
        	double last = 0;
        	double ret = x;
        	while(ret != last) {
        		last = ret;
        		ret = (ret + x / ret) / 2; 
        	}
        	return (int)ret;
        }
    }
};

int main() {
	Solution sol;
//	for (int i = 0; i < 20; i++) {
//		cout << i << ":" << sol.sqrt(i) << endl;
//	}
		cout << 2147395599 << ":" << sol.sqrt(2147395599) << endl;
}
