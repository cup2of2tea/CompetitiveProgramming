#include <iostream>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int tot=0;
    for(int c=0;c<s.size();c++)
        if(s.at(c)=='4'||s.at(c)=='7')
            tot++;
    if(tot==4||tot==7)
        cout<<"YES";
    else
        cout<<"NO";
}