#include <iostream>
#include <set>
#include <string>
#include <utility>

using namespace std;

template < class T, class U>
void print_multiset(multiset<T, U> currentSet){
    for(const auto item : currentSet){
        cout<<item<<endl;
    }
}

class Person{
public:
    string Name;
    int Age;

    Person(string _name, int _age){
        Name = _name;
        Age = _age;
    }

    Person& operator = (const Person &other) {
        Name = other.Name;
        Age = other.Age;
        return *this;
    }

    bool operator < (const Person &rhs) const {
        if(Age == rhs.Age){
            return Name < rhs.Name;
        }
        return Age < rhs.Age;
    }

    bool operator > (const Person &rhs) const {
        if(Age == rhs.Age){
            return Name > rhs.Name;
        }
        return Age > rhs.Age;
    }

};


ostream& operator << (ostream &out, const Person &item) {
    out << "Name: " << item.Name << ", Age: " << item.Age;
    return out;
}

int main()
{
    cout<<"\nTesting C++STL multiset for Integer: "<<endl;
    cout<<"-------------------------------------------"<<endl;

    multiset<int, less<int>> set_integer = {5,4,6,7,9};
    set_integer.insert(11);
    print_multiset(set_integer);

    cout<<"\nTesting C++STL multiset for String: "<<endl;
    cout<<"-------------------------------------------"<<endl;

    multiset<string, less<string>> set_string = {"apple", "banana", "melon", "berry", "grape", "orange", "plums"};
    print_multiset(set_string);


    cout<<"\nTesting C++STL multiset for User Defined Types: "<<endl;
    cout<<"-------------------------------------------"<<endl;

    multiset<Person, less<Person>> set_Person;
    set_Person.insert(Person("rajib", 31));
    set_Person.insert(Person("rajib", 29));
    set_Person.insert(Person("sazib", 33));
    set_Person.insert(Person("abhishek", 32));
    set_Person.insert(Person("alamin", 32));
    set_Person.insert(Person("zakee", 30));
    set_Person.insert(Person("nayem", 34));
    set_Person.insert(Person("ridwan", 35));
    print_multiset(set_Person);

    
    cout<<"\nTesting C++STL multiset erase, loop until empty: "<<endl;
    cout<<"-------------------------------------------"<<endl;
    while(!set_Person.empty()){
        Person youngestPerson = *set_Person.begin();
        cout<<"Youngest Person = "<< youngestPerson <<endl;
        set_Person.erase(youngestPerson);
    }

    
    return 0;
}