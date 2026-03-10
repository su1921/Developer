#include <iostream>
using namespace std;

class Queue
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
    Queue() : head(nullptr) {}

    void push(int value)
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

    void pop()
    {
        if (head == nullptr)
        {
            return;
        }

        if (head->next == nullptr)
        {
            Node *temp = head;
            head = nullptr;
            delete temp;

            return;
        }

        Node *temp = head;
        head = head->next;
        delete temp;
    }

    int peek()
    {
        if (head == nullptr)
        {
            return -1;
        }

        return head->data;
    }

    void traversal()
    {
        if (head == nullptr)
        {
            return;
        }

        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.pop();

    q.traversal();

}