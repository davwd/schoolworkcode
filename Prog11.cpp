//
//  main.cpp
//  Prog11.Vectors


#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector <string> from;
    vector <string> to;
    string rule;
    getline(cin, rule);
    while (rule != "0")
    {
        long pos = rule.find('>');
        from.push_back(rule.substr(0, pos));
        to.push_back(rule.substr(pos+1,rule.length()-1));
        getline(cin, rule);
    }
    //cout<<"to = "<<to[0]<<endl;
   // cout<<"size of to = "<<to.size()<<endl;

    
    
    vector <string> sentence;
    int j = 0;
    sentence.push_back("0");
    
    while (getline(cin,sentence[j]))
    {
            for(int i=0; i<from.size(); i++)
            {
                size_t pos = sentence[j].find(from[i]);
                size_t sentenceSize=sentence[j].size();
                while (pos<sentenceSize)
                {
                    sentence[j].replace(pos, from[i].length(), to[i]);
                    pos = sentence[j].find(from[i],pos+to[i].length());
                    sentenceSize=sentence[j].size();
                
                }
            }
        cout<<sentence[j]<<endl;
        j++;
        sentence.push_back("0");
    }
   
    return 0;
}
