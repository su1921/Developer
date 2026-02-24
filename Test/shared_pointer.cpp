#include <iostream>
#include <memory>
using namespace std;

class Person
{
private:
    string name;
public:
    Person(string s) : name(s) {}

    void greet()
    {
        cout << "Hello I'm " << name << endl;
    }
};

int main()
{
    shared_ptr<Person> p1 = make_shared<Person>("Suresh");
    p1->greet();

    {
        shared_ptr<Person> p2 = p1;
        p2->greet();
        cout << "Reference count: " << p1.use_count() << endl;
    }
    
    cout << "Reference count: " << p1.use_count() << endl;
}