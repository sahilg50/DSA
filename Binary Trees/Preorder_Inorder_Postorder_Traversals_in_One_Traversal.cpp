#include <iostream>
#include <stack>
#include <algorithm>
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

void allTraversal(TreeNode *root, vector<int> &pre, vector<int> &in, vector<int> &post)
{
    stack<pair<TreeNode *, int>> st;

    if (root != NULL)
        st.push({root, 1});

    while (!st.empty())
    {
        auto node = st.top();
        st.pop();

        // this is part of pre
        // increment 1 to 2
        // push the left side of the tree
        if (node.second == 1)
        {
            pre.push_back(node.first->val);
            node.second++;
            st.push(node);

            if (node.first->left != NULL)
            {
                st.push({node.first->left,
                         1});
            }
        }

        // this is a part of in
        // increment 2 to 3
        // push right
        else if (node.second == 2)
        {
            in.push_back(node.first->val);
            node.second++;
            st.push(node);

            if (node.first->right != NULL)
            {
                st.push({node.first->right,
                         1});
            }
        }
        // don't push it back again
        else
        {
            post.push_back(node.first->val);
        }
    }
}

struct TreeNode *newNode(int val)
{
    TreeNode *node = &TreeNode(val);

    return (node);
}

int main()
{

    TreeNode *root = newNode(1);
    root->left = newNode(2);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right = newNode(3);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    vector<int> pre, in, post;
    allTraversal(root, pre, in, post);

    cout << "The preorder Traversal is : ";
    for (auto nodeVal : pre)
    {
        cout << nodeVal << " ";
    }
    cout << endl;
    cout << "The inorder Traversal is : ";
    for (auto nodeVal : in)
    {
        cout << nodeVal << " ";
    }
    cout << endl;
    cout << "The postorder Traversal is : ";
    for (auto nodeVal : post)
    {
        cout << nodeVal << " ";
    }
    cout << endl;

    return 0;
}