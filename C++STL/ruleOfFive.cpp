#include <iostream>
#include <utility> // for using move
using namespace std;

class ResourceManager
{
private:
    int* data;
    size_t size;

public:
    // default constructor
    ResourceManager(size_t sz = 0) : data(new int[sz]), size(sz)
    {
        cout << "Default Constructor is called" << endl;
    }

    // Destructor
    ~ResourceManager()
    {
        delete[] data;
        cout << "Destructor is called" << endl;
    }

    // copy constructor
    ResourceManager(const ResourceManager& other)
    {
        data = new int[other.size];
        size = other.size;
        copy(other.data, other.data + other.size, data);
        cout << "Copy Constructor is called" << endl;
    }

    // copy assignment operator
    ResourceManager& operator=(const ResourceManager& other)
    {
        if (this != &other)
        {
            delete[] data;
            data = new int[other.size];
            size = other.size;
            copy(other.data, other.data + other.size, data);
        }
        cout << "Copy assignment operator is called" << endl;
        return *this;
    }

    // Move constructor
    ResourceManager(ResourceManager&& other) noexcept
    {
        data = other.data;
        size = other.size;
        delete[] other.data;
        other.size = 0;
        cout << "Move constructor is called" << endl;
    }

    // Move assignment operator
    ResourceManager& operator=(ResourceManager&& other) noexcept
    {
        if (this != &other)
        {
            delete[] data;
            data = other.data;
            size = other.size;

            delete[] other.data;
            other.size = 0;
        }
        cout << "Move Assignment Operator is called" << endl;
        return *this;
    }
};

int main()
{
    // Creating an object using default constructor
    ResourceManager obj1(5);

    // Creating an object using Copy constructor
    ResourceManager obj2 = obj1;

    // Creating an object using Copy assignment operator
    ResourceManager obj3;
    obj3 = obj1;

    // Creating an object using Move constructor
    ResourceManager obj4 = move(obj1);

    // Creating an object using Move assignment operator
    ResourceManager obj5;
    obj5 = move(obj2);

    return 0;
}
