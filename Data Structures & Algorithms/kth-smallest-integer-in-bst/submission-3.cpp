/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    pair<int, int> numNodesTree(TreeNode* root, int k, int progress) {
        if (!root) return {progress, -1};

        auto [count, val] = numNodesTree(root->left, k, progress);

        //cout << "root val: " << root->val << " numReturnedLeft: " << count << endl;
        //cout << "root val: " << root->val << " progress: " << progress << endl;

        if (val != -1) {
            return {0, val};
        } else if (count + 1 == k) {
            return {0, root->val};
        }

        auto [countTwo, valTwo] = numNodesTree(root->right, k, count + 1);

        //cout << "root val: " << root->val << " numReturnedRight: " << countTwo << endl;

        if (valTwo != -1) {
            return {0, valTwo};
        }

        return {countTwo, -1};
    }

    int kthSmallest(TreeNode* root, int k) {
        auto [count, node] = numNodesTree(root, k, 0);

        return node;
    }
};
