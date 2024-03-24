#include <iostream>
using namespace std;

class complex{
	int real, imag;
	public:
	complex(int a, int b): real(a), imag(b){}
	complex(){}
	complex operator + (const complex &obj) const{
		complex result;
		result.real = real + obj.real;
		result.imag = imag + obj.imag;
		return result;
	}
	void display()const{
		cout<<real<<" + "<<imag<<"i"<<endl;
	}
};

int main(){
	complex num1(5, 10);
	complex num2(2, 3);

	complex c3;
	c3 = num1 + num2;
	c3.display();

}
