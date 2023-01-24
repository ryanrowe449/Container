#include "doubleContainer.h"
#include<iostream>
using namespace std;
DoubleContainer::DoubleContainer(){
    //delete [] content;
    content = new double[5];
    for (int i = 0; i < 5; i++){
        content[i] = 0.0;
    }
    maxsize = 5;
    currsize = 5;
}

DoubleContainer::DoubleContainer(double* contents, int size){
    content = contents;
    currsize = size;
    maxsize = size;
}

DoubleContainer::~DoubleContainer(){
    if (currsize != 0){
        delete [] content;
    }
}

DoubleContainer::DoubleContainer(const DoubleContainer& x){
    //delete [] content;
    content = new double[x.maxsize];
    maxsize = x.maxsize;
    currsize = x.currsize;
    for (int i = 0; i < x.currsize; i++){
        content[i] = x.content[i];
    }
}

void DoubleContainer::operator=(const DoubleContainer& x){
    //delete [] content;
    content = new double[x.maxsize];
    maxsize = x.maxsize;
    currsize = x.currsize;
    for (int i = 0; i < x.currsize; i++){
        content[i] = x.content[i];
    }
}

//maybe I just cannot modify content, as it will be deleted
void DoubleContainer::add(double x){
    if (maxsize == currsize){
        maxsize++;
        double* contents = new double[maxsize];
        for (int i = 0; i < currsize; i++){
            contents[i] = content[i];
        }
        delete [] content;
        content = contents;
    }
    content[currsize++] = x;
}

void DoubleContainer::clear(){
    currsize = 0;
    maxsize = 0;
    double * contents = new double[0];
    //delete [] content;
    content = contents;
}

DoubleContainer DoubleContainer::remove(){
    int newsize = currsize--;
    double * contents = new double[newsize];
    for (int i = 0; i < newsize; i++){
        contents[i] = content[i];
    }
    return DoubleContainer(contents, newsize);
}

DoubleContainer DoubleContainer::operator+(DoubleContainer x){
    double * contents = new double [maxsize];
    for (int i = 0; i < currsize; i++){
        contents[i] = content[i] + x.content[i];
    }
    return DoubleContainer(contents, maxsize);
}

DoubleContainer operator-(DoubleContainer x, DoubleContainer y){
    double * contents = new double[x.maxsize];
    for (int i = 0; i < x.currsize; i++){
        contents[i] = x.content[i] - y.content[i];
    }
    return DoubleContainer(contents, x.maxsize);
}

void operator-(DoubleContainer& x){
    double * contents = new double[x.maxsize];
    for (int i = 0; i < x.currsize; i++){
        contents[i] = x.content[i] * -1;
    }
    x.content = contents;
}

DoubleContainer DoubleContainer::operator*(double x){
    double * contents = new double[maxsize];
    for (int i = 0; i < currsize; i++){
        contents[i] = content[i] * x;
    }
    return DoubleContainer(contents, maxsize);
}

DoubleContainer DoubleContainer::operator*(DoubleContainer x){
    double * contents = new double[maxsize];
    for (int i = 0; i < currsize; i++){
        contents[i] = content[i] * x.content[i];
    }
    return DoubleContainer(contents, maxsize);
}

double DoubleContainer::GetSize() const{
    return currsize;
}

ostream& operator<<(ostream& o, DoubleContainer x){
    o << "Array contents: <";
    for (int i = 0; i < x.currsize-1; i++){
        o << x.content[i] << ", ";
    }
    o << x.content[x.currsize-1] << ">\n";
}