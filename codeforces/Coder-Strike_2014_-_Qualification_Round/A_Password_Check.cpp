#include <iostream>
 
using namespace std;
 
int main()
{
    string s;
    cin>>s;
    if(s.length()<5)
    {
        cout<<"Too weak"; return 0;
    }
    bool digit = false;
    bool upper = false;
    bool lower = false;
    for(int c=0;c<s.size();c++)
        if(s[c]>='0'&&s[c]<='9') digit = true;
        else if(s[c]>='a'&&s[c]<='z') lower = true;
        else if(s[c]>='A'&&s[c]<='Z') upper = true;
    if(!digit||!upper||!lower)
    {
        cout<<"Too weak"; return 0;
    }
    cout<<"Correct";
}