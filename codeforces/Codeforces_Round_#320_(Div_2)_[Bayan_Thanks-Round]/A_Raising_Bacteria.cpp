#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    long long int n;
    cin>>n;
    long long int act = 1;
    int res = 0;
    while(act <= n){
        if(act & n) res++;
        act*=2;
    }
    cout<<res;
}