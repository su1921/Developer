#include <iostream>
#include <memory>
using namespace std;

class Parent;
class Child;

class Parent
{
public:
    Parent()
    {
        cout << "Parent object is created!\n";
    }

    shared_ptr<Child> child;
};

class Child
{
public:
    Child()
    {
        cout << "Child object is created!\n";
    }

    weak_ptr<Parent> parent;
};

int main()
{
    shared_ptr<Parent> p = make_shared<Parent>();
    shared_ptr<Child> c = make_shared<Child>();

    p->child = c;
    c->parent = p;

    cout << "Parent use count: " << p.use_count() << endl;
    cout << "Child use count: " << c.use_count() << endl;
}
