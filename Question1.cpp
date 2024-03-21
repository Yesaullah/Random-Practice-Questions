#include <iostream>
using namespace std;

class Employee{
    static int NextEmpID;
    const float MaxSalary;
    float Salary;
    string Name;
    int ID;
    public:
    // constrctor
    // Employee(){}
    Employee(float Max, string name) : MaxSalary(Max), Name(name){}
    // class method
    static int GenerateEmpID(){
        return  ++NextEmpID;
    }
    void setID(){
        ID = GenerateEmpID();
    }
    void setSalary(float salary){
        if(salary > MaxSalary){
            Salary = MaxSalary;
        }
        else{
            Salary = salary;
        }
    }
    void Display(){
        cout<<"Employee ID: "<<ID<<endl;
        cout<<"Employee Name: "<<Name<<endl;
        cout<<"Salary: "<<Salary<<endl;
    }
};

int Employee::NextEmpID = 0; // assuming that that whenever the GenerateEmpID method will be called for the first time the employee will get id = 1

int main(){
    Employee e1(40000.0, "Yesaullah");
    Employee e2(50000.0, "Asadullah");

    e1.setSalary(50000.0);
    e2.setSalary(30000);

    e1.setID();
    e2.setID();

    cout<<"Employee 1 info: "<<endl;
    e1.Display();

    cout<<"\nEmployee 2 info: "<<endl;
    e2.Display();

}