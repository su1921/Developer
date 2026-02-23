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

    ~LinkedList()
    {
        Node *curr = head;
        Node *next = nullptr;

        while (curr != nullptr)
        {
            next = curr->next;
            delete curr;
            curr = next;
        }
    }

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

    void remove()
    {
        if (head == nullptr)
        {
            cout << "List is empty!\n";
            return;
        }

        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr && temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
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
        cout << "nullptr\n";
    }

    // Reverse a LinkedList
    void reverse()
    {
        if (head == nullptr || head->next == nullptr)
        {
            return;
        }

        Node *prev = nullptr;
        Node *curr = head;
        Node *next = nullptr;

        while (curr != nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
    }

    // Detect a Cycle
    bool hasCycle()
    {
        if (head == nullptr || head->next == nullptr)
        {
            return false;
        }
        
        Node *slow = head;
        Node *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                return true;
            }
        }

        return false;
    }

    // Find middle node
    void middle()
    {
        if (head == nullptr)
        {
            return;
        }

        Node *slow = head;
        Node *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        cout << slow->data << endl;
    }

    // List is pallindrome 
    bool palindrome()
    {
        Node *slow = head;
        Node *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node *prev = nullptr;
        Node *curr = slow;
        Node *next = nullptr;

        while (curr != nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        Node *temp1 = head;
        Node *temp2 = prev;

        while (temp2 != nullptr)
        {
            if (temp1->data != temp2->data)
            {
                return false;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return true;
    }

    void removeNthFromEnd(int n)
    {
        if (head == nullptr)
        {
            return;
        }

        Node *slow = head;
        Node *fast = head;

        for (int i = 0; i < n; i++)
        {
            if (fast == nullptr)
            {
                return;
            }

            fast = fast->next;
        }

        if (fast == nullptr)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }


        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }

        Node *temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
    }

};

int main()
{
    LinkedList ll;

    ll.insert(1);
    ll.insert(2);
    ll.insert(3);
    ll.insert(4);
    ll.insert(5);
    // ll.remove();
    ll.traversal();

    //ll.reverse();
    //ll.traversal();

    //cout << "hasCycle: " << ll.hasCycle() << endl;

    // cout << "Middle node: "; 
    // ll.middle();

    //cout << "Palindrome: " << ll.palindrome() << endl;

    ll.removeNthFromEnd(5);
    ll.traversal();
}