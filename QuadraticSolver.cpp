/**
 * This program computes various quantities that are used in characterizing a parabola and solves the quadratic equation when f(x)= 0 <br>
 * @author David Holguin Saavedra
 * <pre>
 * Date: 02/21/2022
 * CSC 1253 Project # 1 Section # 1 <br>
 * Instructor: Dr. Duncan
 * File: QuadraticSolver.cpp
 * </pre>
*/

#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;
int main()

{
    cout<<fixed;
    double quad, lin, cons;
    
    cout<<"Enter a, b, and c for the function f(x) = ax^2 + bx + c  -> ";
    cin>> quad>> lin>> cons;

    if (quad==0)
        cout<<"\nERROR: The coefficient of the quadratic term must be non-zero.\n"<<endl;
    else
    {
        cout<<"\n"<<"Quadratic Equation: f(x)= ";
        if (quad==-1)
            cout<<"-";
        else if (quad!=1)
            cout<<setprecision(3)<<quad;
        cout<<"x^2 ";
        if (lin!=0)
        {
            if (lin<0)
                cout<<"- ";
            else
                cout<<"+ ";
            if (lin!=1&&lin!=-1)
                cout<<setprecision(3)<<abs(lin);
            cout<<"x ";
        }
        if (cons!=0)
        {
            if (cons<0)
                cout<<"- ";
            else
                cout<<"+ ";
            cout<<setprecision(3)<<abs(cons);
        }
        
        double disc= pow(lin,2)-4*quad*cons, rat = (-lin)/(2*quad), irrat = sqrt(abs(disc))/(2*quad);
        cout<<"\n\n"<<"Discriminant: "<<disc<<endl;
        cout<<"Axis of Symmetry: x = "<<rat<<endl;
        cout<<"Vertex: ("<<rat<<","<<(-pow(lin,2)/(4*quad)+cons)<<")"<<endl;
        cout<<"y-intercept: ("<<0.000<<","<<cons<<")"<<endl;
        cout<<"The root of the equation f(x) = 0.000: x = {";
        
        if (disc==0)
            cout<<rat;
        else if (disc>0) // modificado: el anterior decia disc>1 por eso mostraba resultado erroneo cuando disc=1. OJO, SI HABLAN DE NUMEROS POSITIVOS ES >0 NO >1
            cout<<rat+irrat<<","<<rat-irrat;
        else
        {
            if (rat==0)
            {
                if (irrat==1)
                    cout<<"i,-i";
                else
                    cout<<irrat<<"i, -"<<irrat<<"i";
            }
            else
            {
                if (irrat==1)
                    cout<<rat<<" + i,"<<rat<<" - i";
                else
                    cout<<rat<<" + "<<abs(irrat)<<"i, "<<rat<<" - "<<abs(irrat)<<"i";
            }
        }
    
        cout<<"}"<<endl<<endl;
    }
    return (0);
}
