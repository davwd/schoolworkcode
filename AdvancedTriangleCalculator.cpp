/**
 * This program uses 3 sides of a triangle and the Heron formula to determine its area.
 * File: TriangleCalculator1.cpp
 * Course: CSC 1253 Section #1 Project #2
 * Instructor: Dr. William Duncan
 * </pre>
 */

#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
    cout<<fixed;
    double a,b,c;
    cout<<"Enter the sides of the triangle -> ";
    cin>>a>>b>>c;
    if(a+b<=c||a+c<=b||b+c<=a)
        cout<<setprecision(3)<<a<<", "<<b<<" and "<<c<<" cannot form the sides of a triangle."<<endl<<endl;
    else
    {
        cout<<"Enter the unit -> ";
        string unit;
        cin>>unit;
        double s=(a+b+c)/2;
        cout<<endl<<"side A = " << setprecision(3)<<a<<" "<<unit<<";\t"<<"side B = "<<setprecision(3)<<b<<" "<<unit<<";\t"<<"side C = "<<setprecision(3)<<c<<" "<<unit<<endl<<"Perimeter = "<<setprecision(3)<<a+b+c<<" "<<unit<<endl<<"area: "<<setprecision(3)<<sqrt(s*(s-a)*(s-b)*(s-c))<<" sq "<<unit<<endl<<"Classification: ";
        double a2=a*a, b2=b*b, c2=c*c;
        if (a >= b)
        {
            if (a >= c)
            {
                if (a2 == b2+c2)
                    cout<<"Right Triangle since "<<a<< "^2 = "<<b<< "^2 + "<<c<< "^2"<<endl;
                else if (a2 < b2+c2)
                    cout<<"Acute Triangle since "<<a<< "^2 < "<<b<< "^2 + "<<c<< "^2"<<endl;
                else
                    cout<<"Obtuse Triangle since "<<a<< "^2 > "<<b<< "^2 + "<<c<< "^2";
                
            }
            else
            {
                if (c2 == a2+b2)
                    cout<<"Right Triangle since "<<c<< "^2 = "<<a<< "^2 + "<<b<< "^2"<<endl;
                else if (c2 < a2+b2)
                    cout<<"Acute Triangle since "<<c<< "^2 < "<<a<< "^2 + "<<b<< "^2"<<endl;
                else
                    cout<<"Obtuse Triangle since "<<c<< "^2 > "<<a<< "^2 + "<<b<< "^2"<<endl;
            }
        }
        else if (b >= c)
        {
            if (b2 == c2+a2)
                cout<<"Right Triangle since "<<b<< "^2 = "<<a<< "^2 + "<<c<< "^2"<<endl;
            else if (b2 < c2+a2)
                cout<<"Acute Triangle since "<<b<< "^2 < "<<a<< "^2 + "<<c<< "^2"<<endl;
            else
                cout<<"Obtuse Triangle since "<<b<< "^2 > "<<a<< "^2 + "<<c<< "^2"<<endl;
        }
        else
        {
            if (c2 == b2+a2)
                cout<<"Right Triangle since "<<c<< "^2 = "<<a<< "^2 + "<<b<< "^2"<<endl;
            else if (c2 < b2+a2)
                cout<<"Acute Triangle since "<<c<< "^2 < "<<a<< "^2 + "<<b<< "^2"<<endl;
            else
                cout<<"Obtuse Triangle since "<<c<< "^2 > "<<a<< "^2 + "<<b<< "^2"<<endl;
        }
        
        
    }
    
    return 0;
}
