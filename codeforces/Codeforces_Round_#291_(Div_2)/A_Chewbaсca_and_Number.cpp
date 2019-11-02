#include <iostream>
#include <random>
#include <utility>
#include <vector>
#include <algorithm>
#include <cstdlib>
 
using namespace std;
 
 
int main()
{
    string s;
    cin>>s;
    for(int c=0;c<s.size();c++)
        s[c]=min(s[c],(char)((9-(s[c]-'0'))+'0'));
    if(s[0]=='0') s[0]='9';
 
    cout<<s;
    
}