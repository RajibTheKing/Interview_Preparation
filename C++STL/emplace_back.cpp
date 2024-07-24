#include <iostream>
#include <vector>

using namespace std;

class Person
{
private:
    string name;
    int age;

public:
    Person(string n, int a)
    {
        name = n;
        age = a;
    }

    void showValues()
    {
        cout << "Name: " << name << ", age = " << age << endl;
    }
};

int main()
{
    vector<Person> vec;
    vec.push_back(Person("rajib", 33));
    vec.emplace_back("abhishek", 34);

    for (auto& x : vec)
    {
        x.showValues();
    }
    return 0;
}