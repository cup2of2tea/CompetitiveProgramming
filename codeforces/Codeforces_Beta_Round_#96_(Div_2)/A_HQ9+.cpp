#include <iostream>
 
using namespace std;
 
int main()
{
    string s;
    getline(cin,s);
    for(int c=0;c<s.size();c++)
        if(s[c]=='H'||s[c]=='Q'||s[c]=='9')
        {
            cout<<"YES";
            return 0;
        }
    cout<<"NO";
}