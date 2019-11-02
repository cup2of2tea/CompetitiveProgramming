#include <bits/stdc++.h>
using namespace std;
 
 
int main()
{
    int N;
    cin>>N;
    string s;
    cin>>s;
    int act = 0;
    for(int c=0;c<s.size();c++) {
        if(s[c]=='+') act++;
        else act--;
        act=max(act,0);
    }
    cout<<act;
}