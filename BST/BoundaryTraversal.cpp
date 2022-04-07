#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BST
{
private:
    TreeNode *head = nullptr;

    TreeNode *insertNode(TreeNode *root, int data)
    {
        if (root == nullptr)
            return new TreeNode(data);

        else if (data < root->val)
            root->left = insertNode(root->left, data);

        else
            root->right = insertNode(root->right, data);

        return root;
    };

    bool isLeaf(TreeNode *node)
    {
        if (node->left == nullptr && node->right == nullptr)
            return true;
        else
            return false;
    };

    void addLeftBoundary(TreeNode *root, vector<int> &res)
    {
        TreeNode *cur = root->left;
        while (cur)
        {
            if (!isLeaf(cur))
                res.push_back(cur->val);

            if (cur->left)
                cur = cur->left;
            else
                cur = cur->right;
        }
    };

    void addRightBoundary(TreeNode *root, vector<int> &res)
    {
        vector<int> temp;
        TreeNode *cur = root->right;
        while (cur)
        {
            if (!isLeaf(cur))
                temp.push_back(cur->val);
            if (cur->right)
                cur = cur->right;
            else
                cur = cur->left;
        }

        for (int i = temp.size() - 1; i >= 0; --i)
        {
            res.push_back(i);
        }
    };

    void addLeaves(TreeNode *root, vector<int> &res)
    {
        if (isLeaf(root))
        {
            res.push_back(root->val);
            return;
        }
        // Left recursion
        if (root->left)
            addLeaves(root->left, res);
        // Right Recursion
        if (root->right)
            (root->right, res);
    };

    vector<int> printBoundary(TreeNode *root)
    {
        vector<int> res;
        if (!root)
            return res;

        if (!isLeaf(root))
            res.push_back(root->val);

        addLeftBoundary(root, res);

        // add leaf nodes
        addLeaves(root, res);

        addRightBoundary(root, res);
        return res;
    }

public:
    void insert(int data)
    {
        head = insertNode(head, data);
    }

    void boundaryTraversal()
    {
        vector<int> res;
        res = printBoundary(head);
        cout << endl
             << "The boundary order traversal of the given tree is: ";
        for (auto i : res)
        {
            cout << i << " ";
        }
        cout << endl;
    }
};

int main()
{
    int arr[] = {5, 10, 6, 9, 7, 8, 1, 4, 2, 3};
    int size = sizeof(arr) / sizeof(int);

    BST g;
    for (int i = 0; i < size; i++)
    {
        g.insert(arr[i]);
    }

    g.boundaryTraversal();
    return 0;
}