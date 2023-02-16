/**
 * This program prompts the user for vector dimensions and their coordinates. It performs and displays various operations with them like vector addiction, substraction, and dot product.
 * @author David Holguin Saavedra
 * <pre>
 * Date: 04/20/2022
 * Course: CSC 1253  Section 1 <br>
 * Programing Project #: 4 <br>
 * Instructor: Dr. Duncan <br>
 * File: VectorManipulator.cpp
 * </pre>
*/

#include <iostream>
#include <sstream>
#include <math.h>
using namespace std;

/**
 * Gives the dimension of the specified vector
 * @param v a vector in dimension-coordinates format
 * @return the dimension of this vecot
 */
int dim(const double v[])
{ return v[0];}

/**
 * Gives a string representation of this vector in the form
 * <x1, x2, ..., xn>, where x1 is the second element of the array,
 * x2, the second element of the array, etc and n is the dimension
 * of the vector and the first element of the array.
 * @param v a dimension-coordinates array representation of a
 * vector.
 * @return a string representation of the specified vector
 */

string vtos(const double v[])
{
    stringstream sout;
    sout<<"<"<< v[1];
    for (int i=2; i<=v[0]; i++)
        sout<<", "<<v[i];
    sout<<">";
    return sout.str();
}

/**
 * Computes the length of this vector
 * @param v a dimension-coordinates representation of a vector
 * @return the length of the specified vector
 */
double length(const double v[])
{
    double ss=0;
    for (int i=1; i<=v[0]; i++)
        ss+= v[i]*v[i];
    return sqrt(ss);
}


/**
 * Computes the sum of the specified vectors
 * @param v1 a vector
 * @param v2 a vector
 * @return the sum of the specified vectors if they have the same
 * dimension or NULL, otherwise
 */
double* add(const double v1[], const double v2[])
{
    if (v1[0]!=v2[0])
        return nullptr;
    double* w = new double [dim(v1)+1];
    w[0]=v1[0];
    for (int i=1; i<=v1[0]; i++)
        w[i]= v1[i] + v2[i];
    return w;
    }

/**
 * Computes the difference of the specified vectors
 * @param v1 a vector
 * @param v2 a vector
 * @return the v1-v2 if the vectors have the same
 * dimension or NULL, otherwise
 */
double* sub(const double v1[], const double v2[])
{
    if (v1[0]!=v2[0])
        return nullptr;
    double* w = new double [dim(v1)+1];
    w[0]=v1[0];
    for (int i=1; i<=v1[0]; i++)
        w[i]= v1[i] - v2[i];
    return w;
    }

/**
 * Computes the dot product of two vectors
 * @param v1 a vector
 * @param v2 a vector
 * @return the dot product of v1 and v2 if they have the same
 * dimension; otherwise, NAN
 */
double dot(const double v1[], const double v2[])
{
    if (v1[0]!=v2[0])
        return NAN;
    double sum=0;
    for (int i=1; i<=v1[0]; i++)
        sum+= v1[i] * v2[i];
    return sum;
}

/**
 * Computes the product of a vector and a number (scalar)
 * @param v a vector
 * @param n a number
 * @return a vector whose coordinates are those of v, each
 * multiplied by n; that is, <nv1, nv2, nv3,...,nvn>
 */
double* mult(const double v[], double n)
{
    double* m = new double [dim(v)+1];
    m[0]=v[0];
    for (int i=1; i<=v[0]; i++)
        m[i] = v[i]*n;
    return m;
}

/**
 * Determines whether two vectors are equal; two vectors are
 * equal if they have the same dimension and their
 * corresponding coordinates are equal.
 * @param v1 a vector
 * @param v2 a vector
 * @return true if the specified vectors are equal;
 * otherwise, false
 */
bool equal(const double v1[], const double v2[])
{
    for (int i=0;i<=v1[0];i++)
    {
        if (v1[i]!=v2[i])
        {
            return false;
        }
    }
    return true;
}


int main()
{
    int dim;
    cout<<"Enter the dimension of three vectors -> ";
    cin>>dim;
    if (dim<1)
        cout<<endl<<"ERROR: The dimension of a vector should be greater than 0."<<endl<<endl;
    else
    {
        double* v1 = new double[dim+1];
        double* v2 = new double[dim+1];
        double* v3 = new double[dim+1];
        v1 [0] = dim;
        v2 [0] = dim;
        v3 [0] = dim;
        cout<<"Enter the coordinates of v1 -> ";
        for (int i=1; i<= dim; i++)
            cin>>v1[i];
        cout<<"Enter the coordinates of v2 -> ";
        for (int i=1; i<= dim; i++)
            cin>>v2[i];
        cout<<"Enter the coordinates of v3 -> ";
        for (int i=1; i<= dim; i++)
            cin>>v3[i];
         cout<<endl<< "v1 = "<< vtos(v1) <<endl<< "v2 = "<< vtos(v2)<<endl<< "v3 = "<< vtos(v3)<< endl<<endl;
        cout<<"v1 + v2 = "<< vtos(add(v1,v2))<<endl;
        cout<<"(v2 + v3) * v1 = "<<dot(add(v2,v3),v1)<<endl;
        cout<<"|v2 - v3| = "<<length(sub(v2,v3))<<endl;
        cout<<"v1*v2 = "<<dot(v1,v2)<<" and |v2||v1| = "<<length(v2)*length(v1)<<endl<<endl;
        
        delete[] v1; delete[] v2; delete[] v3;
    }
         
    cout<<"Enter the dimension of three additional vectors -> ";
    cin>>dim;
    if (dim<1)
        cout<<endl<<"ERROR: The dimension of a vector should be greater than 0."<<endl<<endl;
    else
    {
        double* v4 = new double[dim+1];
        double* v5 = new double[dim+1];
        double* v6 = new double[dim+1];
        v4 [0] = dim;
        v5 [0] = dim;
        v6 [0] = dim;
        cout<<"Enter the coordinates of v4 -> ";
        for (int i=1; i<= dim; i++)
            cin>>v4[i];
        cout<<"Enter the coordinates of v5 -> ";
        for (int i=1; i<= dim; i++)
            cin>>v5[i];
        cout<<"Enter the coordinates of v6 -> ";
        for (int i=1; i<= dim; i++)
            cin>>v6[i];
        cout<<endl<< "v4 = "<< vtos(v4) <<endl<< "v5 = "<< vtos(v5)<<endl<< "v6 = "<< vtos(v6)<< endl<<endl;
        cout<<"v4*(v5 + v6) ";
        if (dot(v4,add(v5,v6))==(dot(v4,v5)+dot(v4,v6)))
            cout<<"=";
        else
            cout<<"<>";
        cout<<" v4*v5 + v4*v6"<<endl;
        
        double* vresult1 = new double[dim+1];
        double* vresult2 = new double[dim+1];
        vresult1 = mult(add(v4,v5),(1/(length(add(v4,v5)))));
        vresult2 = add(mult(v5,(1/(length(add(v5,v6))))),mult(v6,(1/(length(add(v5,v6))))));
        cout<<"(v4+v5)/|v4+v5| = "<<vtos(vresult1)<<endl;
        cout<<"v5/|v5+v6| + v6/|v5+v6| = " <<vtos(vresult2)<<endl;
        cout<<"(v4+v5)/|v4+v5|";
        if (equal(vresult1,vresult2))
            cout<<" = ";
        else
            cout<<" <> ";
        cout<<"v5/|v5+v6| + v6/|v5+v6|"<<endl<<endl;
        delete[] vresult1; delete[] vresult2;
        delete [] v4; delete [] v5; delete [] v6;
    }
    return 0;
}
