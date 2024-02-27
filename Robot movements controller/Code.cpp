#include <iostream>
using namespace std;

class robot{
    float d; // the same variable will be used for both the x and y directions 
    float X; // position in x-axis
    float Y; // position in y-axis

    public:
    robot(){ // default constructor
        d = 0;
        X = 0;
        Y = 0;
    }
    robot(float d, float X, float Y){ // parameterized constructor
        this->d = d;
        this->X = X;
        this->Y = Y;
    }
    // move left method
    void moveleft(float d){
        X -= d; // decrease the value of value of x by d
        cout<<"The robot moved to the left by "<<d<<endl;
    }
    void moveright(float d){
        X += d;  // increase the value of x by d
        cout<<"The robot moved to the right by "<<d<<endl;
    }
    void moveforward(float d){
        Y += d;   // increase the value of y by d
        cout<<"The robot moved forward by "<<d<<endl;
    }
    void movereverse(float d){
        Y -= d;  // decrease the value of y by d
        cout<<"The robot moved reverse by "<<d<<endl;
    }
    // getters and setters
    void setX(float X){
        this->X = X;
    }
    void setY(float Y){
        this->Y = Y;
    }
    float getX(){
        return X;
    }
    float getY(){
        return Y;
    }
    // member function for the commands
    void commands(string s, float d){
        int i;
        for(i=0; i<s.length(); ++i){
            char current = s[i];
            switch (current) {
                case 'L':
                    moveleft(d);
                    break;
                case 'R':
                    moveright(d);
                    break;
                case 'F':
                    moveforward(d);
                    break;
                case 'B':
                    movereverse(d);
                    break;
                default:
                    cout<<"Invalid string input."<<endl;
            }
        }
    }

    // copyconstructor
    robot(const robot &r) { 
        X = r.Y; // sets the y value of the old object as the x value of the new object 
        Y = r.X; // sets the x value of the old object as the y value of the new object 
    }
    
};

int main(){
    cout<<"Do you want to move the robot? Enter yes or no: ";
    string choice;
    cin>>choice;
    if(choice == "yes" || choice == "Yes"){
        cout<<"In what sequence of directions do you want to move the robot?\nEnter the sequence without spaces: ";
        string s;
        cin>>s;
        cout<<"Enter the the distance you want the robot to move in each step: ";
        int d;
        cin>>d;
        robot R1;
        R1.commands(s, d);
        cout<<"New position of the robot is:\n"<<R1.getX()<<" in x-direction.\n"<<R1.getY()<<" in y-direction."<<endl;
    }
    else{
        cout<<"The robot did not move."<<endl;
    }

    return 0;
}
