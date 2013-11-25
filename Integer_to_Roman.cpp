#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        string ret;
        int t = 1000;
        char c[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        for (int i = 0, j = 6; i < 4; i++, j = j - 2) {
        	int n = num / t;
        	num = num % t;
        	t = t / 10;
        	if (n < 4) {
        		ret.append(n, c[j]);
        	} else if (n == 4) {
        		ret.append(1, c[j]);
        		ret.append(1, c[j + 1]);
        	} else if (n == 5) {
        		ret.append(1, c[j + 1]);
        	} else if (n < 9) {
        		ret.append(1, c[j + 1]);
        		ret.append(n % 5, c[j]);
        	} else if (n == 9) {
        		ret.append(1, c[j]);
        		ret.append(1, c[j + 2]);
        	}
        }
        return ret;
    }
};


int main() {
	Solution sol;
	for (int i = 1; i < 10; i++) {
		cout << sol.intToRoman(i) << endl;
	}
	cout << sol.intToRoman(530) << endl;
}
