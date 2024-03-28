
// FUNCTION OVERRIDING      // FUNCTION OVERRIDING      // FUNCTION OVERRIDING      // FUNCTION OVERRIDING
// FUNCTION OVERRIDING      // FUNCTION OVERRIDING      // FUNCTION OVERRIDING      // FUNCTION OVERRIDING
// FUNCTION OVERRIDING      // FUNCTION OVERRIDING      // FUNCTION OVERRIDING      // FUNCTION OVERRIDING

#include <iostream>
using namespace std;

class Shape{
    public:
    virtual int Area(){}
    virtual int Perimeter(){}
};

class Reactangle: public Shape{
    int h, w;
    public:
    Reactangle(int height, int width){
        h=height;
        w=width;
    }
    int Area(){
        cout<<"Area of Rectangle: ";
        return h*w;
    }
    int Perimeter(){
        cout<<"Perimeter of Rectangle: ";
        return 2*(h+w);
    }
};

class Circle: public Shape{
    int radius;
    public:
    Circle(int r){
        radius = r;
    }
    int Area(){
        cout<<"Area of Circle: ";
        return 3.142*radius*radius;
    }
    int Perimeter(){
        cout<<"Perimeter of circle: ";
        return  2*3.142*radius;
    }
};

int main(){
    Circle c1(5);
    Reactangle r1(2, 3);
    Reactangle r2(4, 5);

    Shape* shapes[] = {&c1, &r1, &r2};

    int size = sizeof(shapes)/sizeof(Shape);
    int i;
    for(i =0; i<size; i++){
        cout<<"Area of shape "<<i+1<<" = "<<shapes[i]->Area()<<endl;
        cout<<"Perimeter of shape "<<i+1<<" = "<<shapes[i]->Perimeter()<<endl;
    }

    return 0;
}
