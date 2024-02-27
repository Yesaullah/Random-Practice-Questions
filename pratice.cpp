#include<iostream>
using namespace std;
class multiples{
    int a;
    int count = 1;
    public:
    // constructor
    multiples(int a){
        this->a=a;
    }
    void multiple(int arr[]){ // address of an array is passed as a parameter
        int i;
        for(i=0; i<10; i++){
            arr[i] = a*count;
            count++;
        }
    }
};
int main(){
    multiples m(4);
    int arr[10];
    m.multiple(arr);
    int i;
    for(i=0; i<10; i++){
        cout<<"Multiple "<<i+1<<": "<<arr[i]<<endl;
    }

    return 0;
}