#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace::std;

class Solution {
public:
	struct Node {
		char value;
		Node *node;
		Node() {
			this->value = -1;
			this->node = NULL;
		}
	};

    vector<string> wordBreak(string s, unordered_set<string> &dict) {
    	vector<string> ret;
    	Node dicts[128];
    	// init dict tree
    	for (unordered_set<string>::iterator iter; iter != dict.end(); ++iter) {
    		string word = *iter;
    		Node *cur = dicts;
    		for (int i = 0; i < word.size(); ++i) {
    			char c = word[i];
    			if (cur[c].value != -1) {
    				cur = cur[c].node;
    			} else {
    				Node newDict[128];
    				cur[c].value = c;
    				cur[c].node = newDict;
    				cur = newDict;
    			}
    		}
    	}

    	// find word break;
        return ret;
    }
};

int main(void) {
	Solution sol;
	string s = "catsanddog";
	unordered_set<string> set = {"cat", "cats", "and", "sand", "dog"};
	vector<string> ret = sol.wordBreak(s, set);
	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i] << endl;
	}
}