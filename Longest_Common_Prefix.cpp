#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (strs.empty())
            return "";
        sort(strs.begin(), strs.end());
        string s(strs[0]);
        string e(strs[strs.size() - 1]);
        int length = s.length() < e.length() ? s.length() : e.length();
        int i = 0;
        for (; i < length; i++) {
            if (s[i] != e[i])
                break;
        }
        return s.substr(0, i);
    }
};


int main() {
    Solution sol;
    vector<string> s;
    s.push_back("aaaa");
    s.push_back("aaab");
    s.push_back("acac");
    cout << sol.longestCommonPrefix(s) << endl;
}
