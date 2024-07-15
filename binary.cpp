#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int globalMax = INT_MIN;
        maxPathSumHelper(root, globalMax);
        return globalMax;
    }
private:
    int maxPathSumHelper(TreeNode* node, int& globalMax) {
        if (!node) return 0;
        int leftMax = max(maxPathSumHelper(node->left, globalMax), 0);
        int rightMax = max(maxPathSumHelper(node->right, globalMax), 0);
        int currentMax = node->val + leftMax + rightMax;
        globalMax = max(globalMax, currentMax);
        return node->val + max(leftMax, rightMax);
    }
};
int main() {
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution solution;
    int result = solution.maxPathSum(root);
    cout << "Maximum path sum: " << result << endl;
    return 0;
}