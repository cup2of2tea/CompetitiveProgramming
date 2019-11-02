#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
 
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ones = 0;
    int zeros = 0;
    for(int c=0;c<s.size();c++)
    {
        if(s[c]=='1') ones++;
        else zeros++;
    }
    cout<<abs(zeros-ones);
}