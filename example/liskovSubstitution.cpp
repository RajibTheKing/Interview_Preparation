#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Employee
{
public:
    std::string name;
    int salary;
    int bonus;
    virtual int getSalary() = 0;
    virtual int getBonus() = 0;
};

class FullTimeEmployee : public Employee
{
public:
    FullTimeEmployee()
    {
        salary = 3200;
        bonus = 500;
    }
    int getSalary()
    {
        return salary + bonus;
    }
    int getBonus()
    {
        return bonus;
    }
};

class PartTimeEmployee : public Employee
{
public:
    PartTimeEmployee()
    {
        salary = 1200;
        bonus = 200;
    }
    int getSalary()
    {
        return salary;
    }
    int getBonus()
    {
        return bonus;
    }
};


class Freelancer : public Employee
{
public:
    Freelancer()
    {
        salary = 3000;
        bonus = 0;
    }
    int getSalary()
    {
        return salary;
    }
    int getBonus()
    {
        return bonus;
    }
};

void makePayment(vector<Employee*> employees)
{
    for(auto employee : employees)
    {
        int salary = employee->getSalary();
        int bonus = employee->getBonus();
        cout << "Salary: " << salary << ", " << bonus << endl;
    }
}


int main()
{
    vector<Employee*> employees;
    employees.push_back(new FullTimeEmployee());
    employees.push_back(new PartTimeEmployee());
    employees.push_back(new Freelancer());
    makePayment(employees);
}


