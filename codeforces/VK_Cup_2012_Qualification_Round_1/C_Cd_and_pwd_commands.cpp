#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <set>
#include <vector>
using namespace std;
 
 
 
int main()
{
    int n;
    cin>>n;
    string actuel="/";
    for(int c=0;c<n;c++)
    {
        string s1,s2;
        cin>>s1;
        if(s1=="pwd")
            cout<<actuel<<endl;
        else
        {
            cin>>s2;
            if(s2[0]=='/')
                actuel="";
            for(int c=0;c<s2.size();c++)
            {
                if(c==s2.size()-1||s2[c]!='.'||s2[c+1]!='.')
                {
                    actuel=actuel+s2[c];
                }
                else
                {
                    actuel=actuel.substr(0,actuel.size()-1);
                    while(actuel.size()!=0&&actuel[actuel.size()-1]!='/')
                    {
                        actuel=actuel.substr(0,actuel.size()-1);
                    }
                    if(actuel.size()!=0)
                        actuel=actuel.substr(0,actuel.size()-1);
                    c++;
                }
            }
            if(actuel[actuel.size()-1]!='/')
                actuel=actuel+'/';
        }
    }
}