#include <iostream>
using namespace std;

class Tree
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

	Tree() : root(nullptr) {}

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

	bool search(Node *node, int value)
	{
		if (node == nullptr)
		{
			return false;
		}

		if (value == node->data)
		{
			return true;
		}
		else if (value < node->data)
		{
			return search(node->left, value);
		}
		else
		{
			return search(node->right, value);
		}
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
	Tree t;

	t.root = t.insert(t.root, 1);
	t.root = t.insert(t.root, 2);
	t.root = t.insert(t.root, 3);
	t.root = t.insert(t.root, 4);
	
	t.inorder(t.root);

	cout << "\n" << t.search(t.root, 5);
	
	cout << endl;
}