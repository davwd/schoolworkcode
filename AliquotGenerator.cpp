 /**
 * This program computes the sum of all the proper divisors of a positive integer. It also determines whether two positive integers are amicable and generate a special sequence related to sum of proper divisors. All of this is achieved with modular programming using 3 different functions. <br>
 * @author David Holguin Saavedra
 * <pre>
 * Date: 03/22/2022
 * CSC 1253 Project # 3 Section # 1 <br>
 * Instructor: Dr. Duncan
 * File: AliquotGenerator.cpp
 * </pre>
*/

#include <iostream>
using namespace std;

/**
 * Computes the aliquot sum of the specified number
 * @param num an integer
 * @return the aliquot sum of the specified number
 * if it is positive; otherwise, -1;
 */
long rSigma(long num)
{
    if (num<=0)
        return -1;
    else
    {
        long sum=0;
        for (long i=1;i<=num/2; i++)
            if (num%i==0)
                sum+= i;
        return sum;
    }
}

/**
 * Generates the string representation of a series whose terms
 * are increasing and consist of proper divisors of the specified number.
 * @param num an integer
 * @return a string representation of the series when num is
 * greater than 1, "0" when num is 1; otherwise "nan"
 */
string genRSigSeries(long num)
{
    if (num>1)
    {
        string series = "1";
        for (long i=2; i<=num/2; i++)
        {
            if (num%i==0)
            {
                series= series + " + "+ to_string(i);
            }
        }
        return series;
    }
    else if (num==1)
        return "0";
    else
        return "nan";
}

/**
 * Generates the aliquot sequence of a number and determines the
 * length of the sequence.
 * @param num an integer
 * @param sequence the aliquot sequence of the specified number when
 * num is positive; otherwise "nan".
 * @param length the length of the aliquot sequence of the specified
 * number when num is positive; otherwise 0
 */
void aliquot(long num, string& sequence, long& length)
{
    if (num<=0)
    {
        sequence="nan";
        length= 0;
    }
    else
    {
        sequence = to_string (num);
        length=1;
        while (num>0)
            {
                sequence = sequence + ", "+ to_string(rSigma(num));
                length+=1;
                num=rSigma(num);
            }
    }
}

int main()
{
    long posInt1, posInt2, posInt3, imperfInt;
    cout<<"Enter a positive integer for its classification -> ";
    cin>> posInt1;
    if (rSigma(posInt1)==-1)
    {
        cout<<"ERROR: The input must be a postive integer."<<endl<<endl;
    }
    else
    {
        cout<<"s("<<posInt1<<") = ";
        if (rSigma(posInt1)>1)
            cout<<genRSigSeries(posInt1)<<" = ";
        cout<<rSigma(posInt1)<<endl;
        cout<<"s("<<posInt1<<") ";
        if (rSigma(posInt1)==posInt1)
            cout<<"= "<<posInt1<<endl<<posInt1<<" is a perfect number."<<endl<<endl;
        else if (posInt1<rSigma(posInt1))
            cout<<"> "<<posInt1<<endl<<posInt1<<" is an abundant number."<<endl<<endl;
        else
            cout<<"< "<<posInt1<<endl<<posInt1<<" is a deficient number."<<endl<<endl;
    }
   
    cout<<"Enter two positive integers -> ";
    cin>>posInt2>>posInt3;
    if (((posInt2<=0)||(posInt3<=0))||(posInt2==posInt3))
        cout<<"ERROR: The imputs must be distinct positive integers."<<endl;
    else
    {
        cout<<"?amicable("<<posInt2<<","<<posInt3<<") = ";
        if ((rSigma(posInt2)==posInt3)&&(rSigma(posInt3)==posInt2))
            cout<<"true"<<endl;
        else
            cout<<"false"<<endl;
        cout<<"s("<<posInt2<<") = ";
        if (rSigma(posInt2)>1)
            cout<<genRSigSeries(posInt2)<<" = ";
        cout<<rSigma(posInt2)<<endl;
        cout<<"s("<<posInt3<<") = ";
        if (rSigma(posInt3)>1)
            cout<<genRSigSeries(posInt3)<<" = ";
        cout<<rSigma(posInt3)<<endl;
    }
    
    cout<<endl<<"Enter an imperfect positive integer -> ";
    cin>>imperfInt;
    if ((rSigma(imperfInt)==imperfInt)||(imperfInt<=0))
        cout<<"Error: The input must be an imperfect positive integer."<<endl;
    else
    {
        string sequence;
        long length;
        aliquot(imperfInt, sequence, length);
        cout<<"aliquot {"<<imperfInt<<"} = "<<sequence<<endl<<"length: "<<length<<endl;
    }
    cout<<endl;
    return 0;
}
