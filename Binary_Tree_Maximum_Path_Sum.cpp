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
    int maxPathSum(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int ret = root->val;
        maxPathSumRecursive(root, ret);
        return ret;
    }
    
    int maxPathSumRecursive(TreeNode *node, int& maxSum) {
    	if (node->left == NULL && node->right == NULL) {
    		return node->val;
    	} else if (node->right != NULL && node->left != NULL) {
    		int sumLeft = maxPathSumRecursive(node->left, maxSum);
			int sumRight = maxPathSumRecursive(node->right, maxSum);
    		int val = node->val;
    		if (val > maxSum)
    			maxSum = node->val;
    		if (sumLeft > maxSum)
    			maxSum = sumLeft;
    		if (sumRight > maxSum)
    			maxSum = sumRight;
    		if (val + sumLeft > maxSum)
    			maxSum = val + sumLeft;
    		if (val + sumRight > maxSum)
    			maxSum = val + sumRight;
    		if (val + sumLeft + sumRight > maxSum)
    			maxSum = val + sumLeft + sumRight;
    		
    		if (sumLeft < 0 && sumRight < 0)
    			return val;
    		else if (sumLeft > sumRight)
    			return val + sumLeft;
    		else
    			return val + sumRight;
    	} else if (node->left != NULL) {
    		int sumLeft = maxPathSumRecursive(node->left, maxSum);
    		int val = node->val;
    		if (val > maxSum)
    			maxSum = val;
    		if (sumLeft > maxSum)
    			maxSum = sumLeft;
    		if (val + sumLeft > maxSum)
    			maxSum = val + sumLeft;
    			
    		if (sumLeft < 0)
    			return val;
    		else
    			return val + sumLeft;
    	} else if (node->right != NULL) {
    		int sumRight = maxPathSumRecursive(node->right, maxSum);
    		int val = node->val;
    		if (val > maxSum)
    			maxSum = val;
    		if (sumRight > maxSum)
    			maxSum = sumRight;
    		if (val + sumRight > maxSum)
    			maxSum = val + sumRight;
    			
    		if (sumRight < 0)
    			return val;
    		else
    			return val + sumRight;
    	}
    }
};

int main() {
	Solution sol;
	TreeNode *head = new TreeNode(0);
	TreeNode *left1 = head->left = new TreeNode(1);
	TreeNode *right1 = head->right = new TreeNode(2);
	TreeNode *left2 = left1->left = new TreeNode(3); 
	TreeNode *left3 = left1->right = new TreeNode(4); 
	TreeNode *right2 = right1->right = new TreeNode(-4);
	cout << sol.maxPathSum(head);

}

