#include <iostream>
using namespace std;
 
int main()
{
    string s;
    getline(cin,s);
    string hello="hello";
    int c2=0;
    for(int c=0;c<s.size();c++)
    {
        if(hello.at(c2)==s.at(c))
        {
            c2++;
        }
        if(c2>=hello.size())
        {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
}