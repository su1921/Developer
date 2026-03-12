#include <iostream>
using namespace std;

class BST
{
private:
    struct Node
    {
        int data;
        Node *left;
        Node *right;

        Node(int value) : data(value), left(nullptr), right(nullptr) {}
    };

public:
    Node *root;
    BST() : root(nullptr) {}

    Node* insert(Node *node, int value)
    {
        if (node == nullptr)
        {
            return new Node(value);
        }

        if (value < node->data)
        {
            node->left = insert(node->left, value);
        }
        else
        {
            node->right = insert(node->right, value);
        }
        return node;
    }

    void inorder(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }

        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
};

int main()
{
    BST tree;

    tree.root = tree.insert(tree.root, 5);
    tree.root = tree.insert(tree.root, 3);
    tree.root = tree.insert(tree.root, 1);
    tree.root = tree.insert(tree.root, 2);
    tree.root = tree.insert(tree.root, 4);

    tree.inorder(tree.root);

    cout << endl;
}