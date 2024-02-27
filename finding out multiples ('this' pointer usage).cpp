#include<iostream>
using namespace std;

class multiple{
    int n;
    int count = 1;
    public:
    multiple(int n){
        this->n = n;
    }
    void mul(int arr[]){
        int i;
        for(i=0; i<10;i++){
            int temp;
            temp = n*count;
            count++;
            arr[i]=temp;
        }
    }
    void display(int arr[]){
        int j;
        for(j=0; j<10; j++){
            cout<<"   Multiple "<<j+1<<": "<<arr[j]<<endl;
        }
    }
};

int main(){
    multiple *m[3];
    int i;
    int n;
    int arr[10];
    for(i=0; i<3; i++){
        cout<<"Enter an integer you want to find a multiple of: ";
        cin>>n;
        m[i] = new multiple(n);
        int j;
        m[i]->mul(arr);
        cout<<"Multiples of "<<n<<" are: "<<endl;
        m[i]->display(arr);
    }
    delete[] m;
    return 0;
}
