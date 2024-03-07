#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    cout << "Enter a string: ";
    cin >> str;

    int length = str.length();
    int l = 0;
    char read[100] = {""}; 

    for(int i = 0; i < length; i++){
        bool check = true;
        for(int j = 0; j < l; j++){
            if(str[i] == read[j]){
                check = false;
                break;
            }
        }
        if(check){
            read[l] = str[i];
            l++;
        }
    }
    cout << "The length of the string = " << l << endl;
}

