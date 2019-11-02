#include <iostream>
#include <map>
using namespace std;
 
int main()
{
    map<char,char> m;
    m['A']='A';
    m['H']='H';
    m['I']='I';
    m['O']='O';
    m['M']='M';
    m['T']='T';
    m['U']='U';
    m['V']='V';
    m['W']='W';
    m['X']='X';
    m['Y']='Y';
 
    string s;
    cin>>s;
    for(int c=0;c<s.size();c++) {if(s[c]!=m[s[s.size()-1-c]]){cout<<"NO"; return 0;}}
    cout<<"YES";
}