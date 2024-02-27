#include <iostream>
using namespace std;

inline int square(int a){
    return a * a;
}

int main(){
    int a  = 5;

    cout<<"Square = "<<square(2)<<endl;
    cout<<"Square = "<<square(3)<<endl;
    cout<<"Square = "<<square(4)<<endl;
    cout<<"Square = "<<square(5)<<endl;
    cout<<"Square = "<<square(6)<<endl;

    return 0;
}
