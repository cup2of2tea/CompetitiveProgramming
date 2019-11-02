#include <bits/stdc++.h>
using namespace std;
 
 
int main()
{
    int n;
    cin>>n;
    long long a = 0, b = 0;
    for(int c=0;c<n;c++) {
        long long z;
        cin>>z;
        a|=z;
    }
    for(int c=0;c<n;c++) {
        long long z;
        cin>>z;
        b|=z;
    }
    cout<<a+b;
}