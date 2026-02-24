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
    unique_ptr<Person> p1 = make_unique<Person>("Suresh");
    p1->greet();

    unique_ptr<Person> p2 = std::move(p1);

    if (!p1)
    {
        cout << "P1 is deleted!\n";
    }
}