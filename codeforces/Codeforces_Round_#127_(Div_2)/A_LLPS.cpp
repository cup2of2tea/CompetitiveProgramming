#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
 
int main()
{
    string s;
    getline(cin,s);
    string::iterator maxi=max_element(s.begin(),s.end());
    for(int c=0;c<s.size();c++)
        if((*maxi)==s[c])
            cout<<s[c];
}