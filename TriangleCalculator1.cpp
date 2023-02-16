/**
 * This program uses 3 sides of a triangle and the Heron formula to determine its area.
 * File: TriangleCalculator1.cpp
 * Course: CSC 1253 
 * </pre>
 */

#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

void printSides ( double s1, double s2, double s3, string u)
{
    cout<<endl<<"side A = " << setprecision(3)<<s1<<" "<<u<<";\t"<<"side B = "<<setprecision(3)<<s2<<" "<<u<<";\t"<<"side C = "<<setprecision(3)<<s3<<" "<<u<<endl;
}

double perimeter (double s4, double s5, double s6)
{
    return s4+s5+s6;
}

double area (double s7, double s8, double s9)
{
    double semi = perimeter(s7, s8, s9)/2;
    return sqrt(semi*(semi-s7)*(semi-s8)*(semi-s9));
}


int main()
{
    cout<<fixed;
    double a,b,c,s;
    string unit;
    cout<<"Enter the sides of the triangle -> ";
    cin>>a>>b>>c;
    cout<<"Enter the unit -> ";
    cin>>unit;
    s=(a+b+c)/2;
    printSides(a, b, c, unit);
    cout<<"Perimeter = "<<perimeter(a, b, c)<<" "<<unit<<endl;
    cout<<"area: "<<setprecision(3)<<area(a, b, c)<<" sq "<<unit<<endl<<endl;
    
    return 0;
}
