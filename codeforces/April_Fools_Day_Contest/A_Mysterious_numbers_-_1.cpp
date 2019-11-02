#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;
 
 
int main()
{
    string s,s2;
    cin>>s>>s2;
    reverse(s2.begin(),s2.end());
    stringstream ss;
    int a,b;
    ss<<s;
    ss>>a;
    ss.clear();
    ss<<s2;
    ss>>b;
    cout<<a+b;
}