#include <iostream>
#include <memory>
using namespace std;

class Vehicle
{
public:
    virtual void drive() = 0;
    virtual ~Vehicle() = default;
};

class Car : public Vehicle
{
public:
    void drive() override
    {
        cout << "Driving Car!\n";
    }
};

class Bike : public Vehicle
{
public:
    void drive() override
    {
        cout << "Driving Bike!\n";
    }
};

class Factory
{
public:
    static unique_ptr<Vehicle> createVehicle(string type)
    {
        if (type == "car")
        {
            return make_unique<Car>();
        }
        else if (type == "bike")
        {
            return make_unique<Bike>();
        }
        else
        {
            return nullptr;
        }
    }
};

int main()
{
    unique_ptr<Vehicle> v = Factory::createVehicle("bike");

    if (v)
    {
        v->drive();
    }
}