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
public:
    // Function to get the maximum width of a binary tree.
    int getMaxWidth(struct Node *root)
    {
        unordered_map<int, vector<int>> M;
        queue<pair<struct Node *, int>> Q;

        Q.push({root, 1});
        while (!Q.empty())
        {
            struct Node *node = Q.front().first;
            int level = Q.front().second;
            Q.pop();
            M[level].push_back(node->data);
            if (node->left)
                Q.push({node->left, level + 1});
            if (node->right)
                Q.push({node->right, level + 1});
        }

        int maxWidth = 1;
        for (auto &it : M)
        {
            if (it.second.size() > maxWidth)
                maxWidth = it.second.size();
        }
        return maxWidth;
    }
};

int main()
{
    int t;
    cin >> t;
    getchar();
    while (t--)
    {
        string inp;
        getline(cin, inp);
        Node *root = buildTree(inp);

        Solution ob;
        cout << ob.getMaxWidth(root) << endl;
    }
    return 0;
}