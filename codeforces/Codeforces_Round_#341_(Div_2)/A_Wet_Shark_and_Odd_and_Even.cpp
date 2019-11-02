#include <bits/stdc++.h>
using namespace std;
 
 
int main()
{
    long long miniOdd = 1000000000;
    int n;
    cin>>n;
    long long sum = 0;
    for(int c=0;c<n;c++) {
        long long int z;
        cin>>z;
        sum+=z;
        if(z%2==1) miniOdd = min(miniOdd,z);
    }
    if(sum%2==1){
        cout<<sum-miniOdd;
    } else cout<<sum;
}