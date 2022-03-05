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
        stack<Node *> s;
        s.push(root);
        cout << endl
             << "Printing the preorder traversal iteratively." << endl;
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
    return 0;
}