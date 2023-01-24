#include "doubleContainer.h"
#include<iostream>
using namespace std;
int main(){
    //default constructor, add function
    DoubleContainer a;
    a.add(2.0);
    cout << "Container a, created with default constructor and add function\n";
    cout << a << endl;

    //other constructor
    double * myarray = new double[6];
    for (int i = 0; i < 6; i++){
        myarray[i] = 2.0;
    }
    DoubleContainer b(myarray, 6.0);
    
    cout << "Container b, using the two-parameter constructor\n";
    cout << b << endl;

    //addition
    DoubleContainer c = a + b;
    cout << "a + b\n";
    cout << c << endl;

    //subtraction
    //making a new container and printing it
    DoubleContainer d;
    d.clear();
    for (int i = 0; i < 5; i++){
        d.add(1.0);
    }
    cout << "New container d:\n";
    cout << d << endl;
    //making a new container and printing it
    DoubleContainer e;
    e.clear();
    for (int i = 0; i < 5; i++){
        e.add(i);
    }
    cout << "New container e, made using the clear and add functions:\n";
    cout << e << endl;
    //subtracting e from d
    DoubleContainer f = d - e;
    cout << "d - e\n";
    cout << f << endl;

    //negation operator and multiplication operator 1
    DoubleContainer g;
    g.clear();
    for (int i = 4; i < 9; i++){
        g.add(i);
    }
    cout << "New container g:\n";
    cout << g << endl;
    g = g * 5.0;
    cout << "g after every element of content is multiplied by 5:\n";
    cout << g << endl;

    //multiplying two objects
    DoubleContainer h;
    h.clear();
    for (int i = 5; i < 13; i++){
        h.add(i);
    }
    cout << "New container h:\n";
    cout << h << endl;
    cout << "New container i, set equal to h by the deep copy assignment operator overload:\n";
    DoubleContainer i = h;
    cout << i << endl;
    DoubleContainer j = h * i;
    cout << "h * i:\n";
    cout << j << endl;

    //using the negation operator and copy constructor
    DoubleContainer k;
    k.clear();
    for (int i = 10; i < 20; i++){
        k.add(i);
    }
    cout << "New container k:\n" << k << endl;
    -k;
    cout << "k after using the negation operator\n" << k << endl;
    DoubleContainer l(k);
    cout << "New container l using the copy constructor with k as a parameter:\n" << l << endl;
    l.remove();
    l.remove();
    cout << "l after removing two doubles from the end of content:\n" << l << endl;

    //trying to multiply two differently sized arrays
    cout << endl << "Trying to multiply two arrays that are of different sizes:\n";
    if (k.GetSize() == l.GetSize()){
        DoubleContainer m = k * l;
        cout << m;
    }
    else {
        cout << "This cannot be done since the two arrays are of different sizes\n";
        DoubleContainer n;
        cout << n;
    }
}