#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

// Strcuture to create a new node.
struct Node
{
    int data;
    struct Node *left, *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class BST
{
private:
    Node *head = NULL;

    // private Method to insert a node into the BST
    Node *insert(int val, Node *root)
    {
        if (root == NULL)
            return new Node(val);

        else if (val < root->data)
            root->left = insert(val, root->left);

        else
            root->right = insert(val, root->right);

        return root;
    }

    // Private method to print the inorder traversal
    void inorder(Node *root)
    {
        if (root == NULL)
            return;

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    // method to print the inorder traversal iteratively.
    void inorder_iterative(Node *root)
    {
        if (!root)
            return;

        stack<Node *> S;
        cout << endl
             << "Printing the iterative inorder traversal of BT: ";
        while (true)
        {
            if (root != NULL)
            {
                S.push(root);
                root = root->left;
            }
            else
            {
                if (S.empty())
                    break;

                root = S.top();
                S.pop();
                cout << root->data << " ";
                root = root->right;
            }
        }
        return;
    }

    // Method to search the key in the BST.
    bool search(Node *root, int val)
    {
        if (root == NULL)
            return false;

        else if (root->data == val)
            return true;

        else if (val < root->data)
            search(root->left, val);

        else
            search(root->right, val);
    }

    // Method to find the inorder successor.
    Node *inorderSuccessor(Node *root)
    {
        Node *curr = root;
        while (curr && curr->left != NULL)
        {
            curr = curr->left;
        }
        return curr;
    }

    // Method to delete a node from the BST;
    Node *Delete(Node *root, int key)
    {
        if (key < root->data)
            root->left = Delete(root->left, key);

        else if (key > root->data)
            root->right = Delete(root->right, key);

        else
        {
            if (root->left == NULL)
            {
                Node *temp = root->right;
                free(root);
                return temp;
            }
            else if (root->right == NULL)
            {
                Node *temp = root->left;
                free(root);
                return temp;
            }
            else
            {
                Node *temp = inorderSuccessor(root->right);
                root->data = temp->data;
                root->right = Delete(root->right, temp->data);
            }
        }
        return root;
    }

    // Method to print the level order traversal
    void levelOrder_using_queue(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        queue<Node *> q;
        q.push(root);
        cout << endl
             << "WE'll print the level order traversal" << endl;
        while (!q.empty())
        {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++)
            {
                Node *temp = q.front();
                q.pop();
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);

                cout << temp->data << " ";
            }
            cout << endl;
        }
        // TC-> O(n), n is the number of nodes.
        // SC-> O(n), this is because there can be a maximum of n nodes in the queue at a time.
    }

    // Method to print the preorder traversal iteratively.
    void preorder_iterative(Node *root)
    {
        cout << endl
             << "Printing the preorder traversal iteratively." << endl;
        stack<Node *> s;
        s.push(root);
        while (!s.empty())
        {
            Node *temp = s.top();
            s.pop();
            if (temp->right)
                s.push(temp->right);
            if (temp->left)
                s.push(temp->left);
            cout << temp->data << " ";
        }
    }

    // method to print the postorder traversal using two stacks.
    void postorder_Iterative(Node *root)
    {
        if (!root)
            return;
        cout << endl
             << "Printing the portorder traversal iteratively." << endl;
        stack<Node *> s1;
        stack<int> s2;

        s1.push(root);
        while (!s1.empty())
        {
            Node *temp = s1.top();
            s1.pop();
            s2.push(temp->data);
            if (temp->left)
                s1.push(temp->left);
            if (temp->right)
                s1.push(temp->right);
        }

        // poping all the elements from the second stack and printing.
        while (!s2.empty())
        {
            cout << s2.top() << " ";
            s2.pop();
        }
        return;
    }

    // method to get the max height of the binary tree
    int maxHeight(Node *root)
    {
        if (root == NULL)
            return 0;

        int lh = maxHeight(root->left);
        int rh = maxHeight(root->right);

        return 1 + max(lh, rh);
    }

    // method to check if the BT is balanced or not.
    int check(Node *root)
    {
        if (root == NULL)
            return 0;

        int lh = check(root->left);
        if (lh == -1)
            return -1;
        int rh = check(root->right);
        if (rh == -1)
            return -1;

        if (abs(lh - rh) > 1)
            return -1;

        return 1 + max(lh, rh);
    }

    // method to find the diameter of the binary tree
    int getDiameter(Node *root, int &diameter)
    {
        if (root == NULL)
            return 0;

        int lh = getDiameter(root->left, diameter);
        int rh = getDiameter(root->right, diameter);

        diameter = max(diameter, lh + rh);
        return 1 + max(lh, rh);
    }

    // method to find the maximum path sum.
    int getMaxPathSum(Node *node, int &maxi)
    {
        if (node == NULL)
            return 0;

        int leftSum = max(0, getMaxPathSum(node->left, maxi));
        int rightSum = max(0, getMaxPathSum(node->right, maxi));

        maxi = max(maxi, (leftSum + rightSum + node->data));

        return node->data + max(leftSum, rightSum);
    }

public:
    // public method to insert a new node.
    void insertBST(int val)
    {
        head = insert(val, head);
    }

    // public method to print the inorder traversal.
    void inorderBST()
    {
        inorder(head);
    }

    bool searhBST(int key)
    {
        int result = search(head, key);
        cout << endl;
        if (result)
            cout << "The key exists!" << endl;
        else
            cout << "The key does not exist!" << endl;
    }

    // Public method to delete a node from the BST
    void deleteBST(int key)
    {
        Delete(head, key);
    }

    // Public method to print the level order traveral using queue
    void levelOrder_queue()
    {
        levelOrder_using_queue(head);
    }

    // public method to print the preorder traversal iteratively.
    void preorderIterative()
    {
        preorder_iterative(head);
    }

    // public method to iteratively print the inorder traversal.
    void inorderIterative()
    {
        inorder_iterative(head);
    }

    // public method to iteratively print the postorder traversal
    void postorderIterative()
    {
        postorder_Iterative(head);
    }

    // public method to get the max height of the bianry tree
    void height()
    {
        cout << endl
             << "The max height of the binary tree is: " << maxHeight(head) << endl;
    }

    // public method to get the max height of the bianry tree
    void isBalanced()
    {
        int flag = check(head);
        cout << endl
             << "Balnced Tree: " << (flag == -1);
    }

    // public method to get the mdiameter of the binary tree
    void getdiameter()
    {
        int diameter = 0;
        getDiameter(head, diameter);
        cout << endl
             << "The diameter of the binary tree is: " << diameter << endl;
    }

    // public method to find the maxSUm path in the binary tree
    void MaxPathSum()
    {
        int maxi = 0;
        getMaxPathSum(head, maxi);
        cout << endl
             << "THe max path sum is: " << maxi << endl;
    }
};

int main()
{
    BST new_bst;

    int arr[] = {5, 1, 4, 3, 2, 6, 7, 8, 9, 10};
    for (int i : arr)
        new_bst.insertBST(i);

    new_bst.inorderBST();
    new_bst.searhBST(11);
    new_bst.deleteBST(5);
    new_bst.inorderBST();
    new_bst.levelOrder_queue();
    new_bst.preorderIterative();
    cout << endl
         << endl;
    new_bst.inorderBST();
    new_bst.inorderIterative();
    new_bst.postorderIterative();
    new_bst.height();
    new_bst.isBalanced();
    new_bst.getdiameter();
    new_bst.MaxPathSum();

    return 0;
}