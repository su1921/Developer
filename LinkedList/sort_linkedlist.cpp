#include <iostream>
using namespace std;

class LinkedList
{
private:
    struct Node
    {
        int data;
        Node *next;

        Node(int value) : data(value), next(nullptr) {}
    };

    Node *head;

public:
    LinkedList() : head(nullptr) {}

    void insert(int value)
    {
        Node *newNode = new Node(value);

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void traversal()
    {
        if (head == nullptr)
        {
            cout << "List is empty!\n";
            return;
        }

        cout << "List: ";
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "nullptr!\n";
    }

    void sort()
    {
        if (head == nullptr)
        {
            return;
        }

        Node *sortNode = nullptr;
        Node *curr = head;
        Node *next = nullptr;

        while (curr != nullptr)
        {
            next = curr->next;

            if (sortNode == nullptr || sortNode->data > curr->data)
            {
                curr->next = sortNode;
                sortNode = curr;
            }
            else
            {
                Node *temp = sortNode;
                if (temp->next != nullptr && temp->next->data < curr->data)
                {
                    temp = temp->next;
                }
                curr->next = temp->next;
                temp->next = curr;
            }

            curr = next;
        }
        head = sortNode;
    }
};

int main()
{
    LinkedList ll;

    ll.insert(5);
    ll.insert(1);
    ll.insert(2);
    ll.insert(4);
    ll.insert(3);

    ll.sort();
    ll.traversal();
}