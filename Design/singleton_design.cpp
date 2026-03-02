#include <iostream>
using namespace std;

class Singleton
{
private:
    int data;

    Singleton()
    {
        cout << "Singleton class!\n";
    }

public:
    Singleton(const Singleton&) = delete;
    void operator=(const Singleton&) = delete;

    static Singleton& getInstance()
    {
        static Singleton instance;
        return instance;
    }

    void setValue(int value)
    {
        data = value;
    }
    void getValue()
    {
        cout << data << endl;
    }
};

int main()
{
    Singleton &s1 = Singleton::getInstance();
    
    s1.setValue(10);
    s1.getValue();
}