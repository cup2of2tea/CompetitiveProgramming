#include <bits/stdc++.h>
using namespace std;
 
 
 
 
int main()
{
    int n,x,y;
    cin>>n>>x>>y;
    string s;
    cin>>s;
    int res = 0;
    for(int c=0;c<x;c++){
        if(c==y){
            if(s[s.size()-1-c]=='0') res++;
        } else {
            if(s[s.size()-1-c]=='1') res++;
        }
    }
    cout<<res;
}