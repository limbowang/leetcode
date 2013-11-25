#include <iostream>
#include <vector>

using namespace std;

// Using Boyer-Moore String Searching
// But just using bad letters
class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
		int len1, len2;
		for (len1 = 0; haystack[len1] != '\0'; len1++)
			;
		for (len2 = 0; needle[len2] != '\0'; len2++)
			;
		if (len1 < len2)
			return NULL;
		else {
			int badletter[128] = {-1};
			for (int i = 0; needle[i] != '\0'; i++) {
				badletter[needle[i]] = i;
			}
			for (int i = len2 - 1; i < len1; ) {
				int k = len2 - 1;
				int j = i;
				for(; k >= 0; j--, k--) {
					if (needle[k] != haystack[j]) {
						break;
					}
				}
				if (k == -1)
					return haystack + j + 1;
				i += len2 - badletter[needle[k]];
			}
			return NULL;
		}
    }
};

int main() {
	char *a = "";
	char *b = "";
	Solution sol;
	cout << sol.strStr(a, b) << endl;;
	
}
