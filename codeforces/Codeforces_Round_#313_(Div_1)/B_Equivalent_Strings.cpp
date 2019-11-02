#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
 
string lexico(string s)
{
    if(s.size()%2==1) return s;
    string pref = lexico(s.substr(0,s.size()/2)), suff = lexico(s.substr(s.size()/2));
    return min(pref,suff)+max(pref,suff);
}
 
 
int main()
{
    string a,b;
    cin>>a>>b;
    cout<<(lexico(a)==lexico(b)?"YES":"NO");
}