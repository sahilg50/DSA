#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <sstream>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Utility function to create a new Tree Node
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

class Solution
{
private:
    vector<int> findNodes(Node *start, int k, unordered_map<Node *, Node *> &mpp)
    {
        queue<pair<Node *, int>> q; // <node, level>
        q.push({start, 0});
        unordered_map<Node *, bool> vis;
        vis[start] = true;
        vector<int> res;
        while (!q.empty())
        {
            Node *node = q.front().first;
            int level = q.front().second;
            q.pop();
            vis[node] = true;
            if (level > k)
                return res;
            if (level == k)
                res.push_back(node->data);
            if (node->left && !vis[node->left])
                q.push({node->left, level + 1});
            if (node->right && !vis[node->right])
                q.push({node->right, level + 1});
            if (mpp[node] && !vis[mpp[node]])
                q.push({mpp[node], level + 1});
        }
        return res;
    };

    Node *bfsToMapParents(Node *root, unordered_map<Node *, Node *> &mpp, int &target)
    {
        queue<Node *> q;
        q.push(root);
        Node *res;
        while (!q.empty())
        {
            Node *node = q.front();
            q.pop();
            if (node->data == target)
                res = node;
            if (node->left)
            {
                mpp[node->left] = node;
                q.push(node->left);
            }
            if (node->right)
            {
                mpp[node->right] = node;
                q.push(node->right);
            }
        }
        return res;
    };

public:
    vector<int> KDistanceNodes(Node *root, int target, int k)
    {
        unordered_map<Node *, Node *> mpp; // child, parent
        Node *start = bfsToMapParents(root, mpp, target);
        vector<int> ans = findNodes(start, k, mpp);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    getchar();

    Solution x = Solution();

    while (t--)
    {
        string s;
        getline(cin, s);
        Node *head = buildTree(s);

        int target, k;
        cin >> target >> k;
        getchar();

        vector<int> res = x.KDistanceNodes(head, target, k);

        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}