#include <iostream>
#include <algorithm>

using namespace std;

//Strcuture to create a new node.
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

    //Private method to print the inorder traversal
    void inorder(Node *root)
    {
        if (root == NULL)
            return;

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    //Method to search the key in the BST.
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

    //Method to find the inorder successor.
    Node *inorderSuccessor(Node *root)
    {
        Node *curr = root;
        while (curr && curr->left != NULL)
        {
            curr = curr->left;
        }
        return curr;
    }

    //Method to delete a node from the BST;
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

public:
    //public method to insert a new node.
    void insertBST(int val)
    {
        head = insert(val, head);
    }

    //public method to print the inorder traversal.
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

    //Public method to delete a node from the BST
    void deleteBST(int key)
    {
        Delete(head, key);
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

    return 0;
}