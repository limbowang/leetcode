#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int pos = digits.size() - 1;
        int carry = 0;
        int sum = digits[pos] + carry + 1;
        digits[pos] = sum % 10;
        carry = sum / 10;
        for (pos--; pos >= 0; pos--) {
            sum = digits[pos] + carry;
            digits[pos] = sum % 10;
            carry = sum / 10;
            if (carry == 0)
                break;
        }
        if (carry == 1)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};


int main() {
    vector<int> vec;
    Solution sol;
    int i = 99999;
    while (i != 0) {
        vec.insert(vec.begin(), i % 10);
        i = i / 10;
    }
    vec = sol.plusOne(vec);
    for (int j = 0; j < vec.size(); j++) {
        cout << vec[j];
    }
    cout << endl;
}
