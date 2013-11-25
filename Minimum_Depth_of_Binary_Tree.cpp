#include <iostream>

using namespace std;

/**
 Definition for binary tree
**/
struct TreeNode {
    int val;
    TreeNode *left;
	TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minDepth(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (root == NULL)
        	return 0;
		return minDepthRecursive(root, 1);
    }
    
    int minDepthRecursive(TreeNode *cur, int depth) {
    	if (cur->left == NULL && cur->right == NULL) {
    		return depth;
    	} else if (cur->left != NULL && cur->right != NULL) {
    		int depth1 = minDepthRecursive(cur->left, depth + 1);
    		int depth2 = minDepthRecursive(cur->right, depth + 1);
    		return depth1 < depth2 ? depth1 : depth2;
    	}
		else if (cur->left != NULL) {
    		return minDepthRecursive(cur->left, depth + 1);
    	} else if (cur->right != NULL) {
    		return minDepthRecursive(cur->right, depth + 1);
    	}
    }
};

int main() {
	int a[] = {0, 1, 2, 3, 4, 5};
	Solution sol;
	TreeNode *head = new TreeNode(0);
	TreeNode *left1 = head->left = new TreeNode(1);
	TreeNode *right1 = head->right = new TreeNode(2);
	TreeNode *left2 = left1->left = new TreeNode(3); 
	TreeNode *right2 = right1->right = new TreeNode(4);
	cout << sol.minDepth(head);

}

