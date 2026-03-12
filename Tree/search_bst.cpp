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
            return node;
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

    bool search(Node *node, int key)
    {
        if (node == nullptr)
        {
            return false;
        }

        if (key == node->data)
        {
            return true;
        }
        else if (key < node->data)
        {
            search(node->left, key);
        }
        else
        {
            search(node->right, key);
        }

        return false;
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

    cout << tree.search(tree.root, 6) << endl;
}