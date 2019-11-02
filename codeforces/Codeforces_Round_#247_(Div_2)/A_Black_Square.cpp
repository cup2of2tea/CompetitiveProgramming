#include <iostream>
 
using namespace std;
 
int blabla[4];
 
int main()
{
    for(int c=0;c<4;c++) cin>>blabla[c];
    string s;
    cin>>s;
    int res = 0;
    for(int c=0;c<s.size();c++) res+=blabla[s[c]-'1'];
    cout<<res;
}