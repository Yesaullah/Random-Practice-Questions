#include <iostream>
using namespace std;

// A SOFTWARE HOUSE:
//  A) EMPLOYEES :    name, age, joining date
//      1) DEVELOPERS ( frontend or backend)
//      2) DEBUGGERES ( Manual debugger or Auto debugger )
//      3) TEAM LEAD IS BOTH A DEVELOPER AND A DEBUGGER ( can display display all the details )

class Employee{
    protected:
    string Name;
    int Age;
    string JoiningDate;
    public:
    Employee(){}
    Employee(string name, int age, string date):Name(name),Age(age),JoiningDate(date){}
    //accessors
    string GetName(){
        return Name;
    }
    int GetAge(){
        return Age;
    }
    string GetDate(){
        return JoiningDate;
    }
    void setName(string name){
        Name = name;
    }
    void setAge(int age){
        Age = age;
    }
    void setDate(string date){
        JoiningDate = date;
    }
};

class Developer : virtual public Employee{
    protected:
    string DevRole;
    public:
    Developer(){}
    Developer(string name, int age, string date, string role){
        Name = name;
        Age = age;
        JoiningDate = date;
        DevRole = role;
    }
    void setDevName(string name){
        Name = name;
    }
    void setDevAge(int age){
        Age = age;
    }
    void setDevDate(string date){
        JoiningDate = date;
    }
    void setDevRole(string role){
        DevRole = role;
    }
    string getDevName(){
        return Name;
    }
    string getDevDate(){
        return JoiningDate;
    }
    int getDevAge(){
        return Age;
    }
    string getDevRole(){
        return DevRole;
    }
};

class Debugger : virtual public Employee{
    protected:
    string DebRole;
    public:
    Debugger(){}
    Debugger(string name, int age, string date, string role){
        Name = name;
        Age = age;
        JoiningDate = date;
        DebRole = role;
    }
    void setDebName(string name){
        Name = name;
    }
    void setDebAge(int age){
        Age = age;
    }
    void setDebDate(string date){
        JoiningDate = date;
    }
    void setDebRole(string role){
        DebRole = role;
    }
    string getDebName(){
        return Name;
    }
    string getDebDate(){
        return JoiningDate;
    }
    int getDebAge(){
        return Age;
    }
    string getDebRole(){
        return DebRole;
    }
};

class TeamLead : public Developer, public Debugger{
    string LeadRole;
    Debugger* debuggers[10]; // assuming there could be max 10 debuggers in a team
    int debcount = 0;
    Developer* developers[10]; // assuming there could be max 10 developers in a team
    int devcount = 0;
    public:
    TeamLead(string name, int age, string date){
        Name = name;
        Age = age;
        JoiningDate = date;
        LeadRole = "Developer and Debugger";
    }
    void setDebugger(string name, int age, string date, string role){
        if(debcount<10){
            debuggers[debcount] = new Debugger(name,age,date,role);
            debcount++;
        }
        else{
            cout<<"No more debuggers can be added."<<endl;
        }
    }
    void setDeveloper(string name, int age, string date, string role){
        if(devcount<10){
            developers[devcount] = new Developer(name,age,date,role);
            devcount++;
        }
        else{
            cout<<"No more developers can be added."<<endl;
        }
    }
    void display(){
        cout<<"Details of the Team Lead: "<<endl;
        cout<<" Name: "<<Name<<endl;
        cout<<" Age: "<<Age<<endl;
        cout<<" Date of joining: "<<JoiningDate<<endl;
        cout<<" Role: "<<LeadRole<<endl;
        cout<<"\nDetails of Debuggers: "<<endl;
        int i;
        for(i=0; i<debcount; i++){
            cout<<" Debgger "<<i+1<<": "<<endl;
            cout<<"     Name: "<<debuggers[i]->getDebName()<<endl;
            cout<<"     Age: "<<debuggers[i]->getDebAge()<<endl;
            cout<<"     Role: "<<debuggers[i]->getDebRole()<<endl;
            cout<<"     Date of joining: "<<debuggers[i]->getDebDate()<<endl;
        }
        for(i=0; i<devcount; i++){
            cout<<" Developer "<<i+1<<": "<<endl;
            cout<<"     Name: "<<developers[i]->getDevName()<<endl;
            cout<<"     Age: "<<developers[i]->getDevAge()<<endl;
            cout<<"     Role: "<<developers[i]->getDevRole()<<endl;
            cout<<"     Date of joining: "<<developers[i]->getDevDate()<<endl;
        }
    }
};

int main(){
    TeamLead lead("Yesaullah Sheikh", 18, "10-January-2023");
    lead.setDebugger("Hamza", 19, "10-March-2022", "Manual debugger");
    lead.setDebugger("Muneeb", 20, "20-December-2021", "Auto debugger");
    lead.setDeveloper("Murtaza", 21, "10-June-2019", "Frontend developer");
    
    lead.display();

    return 0;
}
