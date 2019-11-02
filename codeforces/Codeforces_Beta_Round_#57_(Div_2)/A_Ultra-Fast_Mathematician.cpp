#include <iostream>
 
 
using namespace std;
int main()
{
string s1,s2;
cin>>s1>>s2;
for(int c=0;c<s1.size();c++)
{
if(s1.at(c)!=s2.at(c))
        cout<<1;
else
        cout<<0;
}
}