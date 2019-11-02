#include <iostream>
 
using namespace std;
 
int main()
{
    string s;
    cin>>s;
    if(s.size()<7)
        cout<<"NO";
    else
    {
        char precedent=s[0];
        int actuel=1;
        for(int c=1;c<s.size();c++)
        {
            if(precedent==s[c])
                actuel++;
            else
            {
                precedent=s[c];
                actuel=1;
            }
            if(actuel==7)
            {
                cout<<"YES";
                return 0;
            }
        }
        cout<<"NO";
    }
}