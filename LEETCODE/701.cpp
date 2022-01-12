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
class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {

        //base case
        if (root == NULL)
            return new TreeNode(val);
        if (val > root->val)
            root->right = insertIntoBST(root->right, val);
        else
            root->left = insertIntoBST(root->left, val);

        return root;
    }
};

/*
TC: O(log2(N)), N is the number of nodes in the binary tree, and log2(N) is the height of the tree. 

SC: O(log2(N)), Is is the memory stack occupied during the recursion call.
*/