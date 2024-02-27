#include <iostream>
using namespace std;

double total = 0;
double employee_total = 0;

class Movie;  // forward declaration of class Movie

class Staff {
    string staffID;
    string EmployeeType;
    double salary;

public:
    Staff() {}
    Staff(string id, string type, double s) : staffID(id), EmployeeType(type), salary(s) {}

    void work(Movie &movie);

    double Total() {
        employee_total += salary;
        return employee_total;
    }
};

class Movie {
    string id;
    string title;
    double TotalBudget;
    double CurrentCost;
    Staff* ProjectLead;   // composition
    Staff* ChiefAnimator; // composition

public:
    Movie() {}
    Movie(string id, string title, double TotalBudget, double CurrentCost)
        : id(id), title(title), TotalBudget(TotalBudget), CurrentCost(CurrentCost) {
    }

    void setBudget(double TotalBudget) {
        this->TotalBudget = TotalBudget;
    }

    void setCost(double CurrentCost) {
        this->CurrentCost = CurrentCost;
    }

    string getTitle() {
        return title;
    }

    double getBudget() {
        return TotalBudget;
    }

    double getCost() {
        return CurrentCost;
    }

    void Production() {
        cout << "The task is in production." << endl;
    }

    double Total() {
        total += CurrentCost;
        return total;
    }

    friend void Staff::work(Movie &movie);
};

void Staff::work(Movie &movie) {
    if (EmployeeType == "Project Lead") {
        double projectCost = movie.getCost();
        if (projectCost >= 200000) {
            cout << "WARNING. The cost is exceeding budget." << endl;
        } else {
            cout << "The cost is still within the budget." << endl;
        }
    } else {
        movie.setCost(movie.getCost() + 10000);
        cout << "The Chief Animator animated, hence PKR 10,000 are added to the current cost." << endl;
    }
}

int main() {
    Movie m1("M-0001", "Fairytales of Love", 200000, 0);
    Movie m2("M-0003", "Maze Runner", 20000, 150000);
    Staff ChiefAnimator1("23K-0019", "Chief Animator", 10000);
    Staff ProjectLead1("23K-0060", "Project Lead", 50000);
    Staff ChiefAnimator2("23K-0038", "Chief Animator", 30000);
    Staff ProjectLead2("23K-0001", "Project Lead", 40000);

    // movie 1
    cout << "Movie 1: " << m1.getTitle() << endl;
    m1.Production();
    ChiefAnimator1.work(m1);
    ProjectLead1.work(m1);
    ChiefAnimator1.work(m1);
    ChiefAnimator1.work(m1);
    ChiefAnimator1.work(m1);
    ChiefAnimator1.work(m1);
    ChiefAnimator1.work(m1);
    ChiefAnimator1.work(m1);
    ProjectLead1.work(m1);

    // movie 2
    cout << "Movie 2: " << m2.getTitle() << endl;
    m2.Production();
    ProjectLead2.work(m2);
    ChiefAnimator2.work(m2);
    ChiefAnimator2.work(m2);
    ChiefAnimator2.work(m2);
    ChiefAnimator2.work(m2);
    ChiefAnimator2.work(m2);
    ChiefAnimator2.work(m2);
    ProjectLead2.work(m2);

    cout << "Total budget of all movies = " << total << endl;
    cout << "Total salaries of all the staff = " << employee_total << endl;

    return 0;
}
