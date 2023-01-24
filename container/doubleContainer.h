#include<iostream>
using namespace std;
class DoubleContainer{
    friend ostream& operator<<(ostream&, DoubleContainer);
    friend DoubleContainer operator-(DoubleContainer, DoubleContainer);
    friend void operator-(DoubleContainer&);
    private:
        double* content;
        int maxsize;
        int currsize;
    public:
        DoubleContainer();
        DoubleContainer(double*, int);
        ~DoubleContainer();                         //destructor
        DoubleContainer(const DoubleContainer&);    //copy constructor
        void operator=(const DoubleContainer&);     //and deep copy assignment
        void add(double);
        void clear();
        DoubleContainer remove();
        DoubleContainer operator+(DoubleContainer);
        DoubleContainer operator*(double);
        DoubleContainer operator*(DoubleContainer);
        double GetSize() const;
        //void SetDouble(double);
};