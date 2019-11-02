#include <iostream>
#include <vector>
#include <time.h>
#include <cstdlib>
#include <cstdio>
using namespace std;
 
 
 
int main()
{
    string s;
    cin>>s;
    int k;
    cin>>k;
    if(s.size()%k != 0)
    {
        cout<<"NO";
        return 0;
    }
    int l = s.size()/k;
    for(int c=0;c<s.size();c+=l)
    {
        for(int c2=0;c2<l;c2++)
        {
            if(s[c+c2] != s[c+l-c2-1])
            {
                cout<<"NO";
                return 0;
            }
        }
    }
    cout<<"YES";
}