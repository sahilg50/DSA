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

        // this is part of PreOrder
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

        // this is a part of InOrder
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

int main()
{

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2, new TreeNode(4), new TreeNode(5));
    root->right = new TreeNode(3, new TreeNode(6), new TreeNode(7));

    vector<int> pre, in, post;
    allTraversal(root, pre, in, post);

    cout << "Preorder Traversal: ";
    for (auto nodeVal : pre)
        cout << nodeVal << " ";

    cout << endl;
    cout << "Inorder Traversal: ";
    for (auto nodeVal : in)
        cout << nodeVal << " ";

    cout << endl;
    cout << "Postorder Traversal: ";
    for (auto nodeVal : post)
        cout << nodeVal << " ";

    return 0;
}
/*
If N is number of nodes in the binary tree then:
TC-> O(3*N)
SC-> O(4*N)
*/