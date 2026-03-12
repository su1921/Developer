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