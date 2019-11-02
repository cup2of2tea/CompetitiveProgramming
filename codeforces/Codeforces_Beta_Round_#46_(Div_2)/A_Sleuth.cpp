#include <iostream>
 
using namespace std;
 
char truc[6]={'a','e','i','o','u','y'};
 
int main()
{
        string s;
        getline(cin,s);
        for(int c=s.size()-1;c>=0;c--)
        {
                if(s.at(c)<='Z'&&s.at(c)>='A')
                        s.at(c)+='a'-'A';
                if(s.at(c)<='z'&&s.at(c)>='a')
                {
                        for(int c2=0;c2<6;c2++)
                                if(truc[c2]==s.at(c))
                                {
                                        cout<<"YES";
                                        return 0;
                                }
                        cout<<"NO";
                        return 0;
                }
        }
        cout<<"NO";
}