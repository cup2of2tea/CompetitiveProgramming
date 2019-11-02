#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;
 
int main()
{
    vector<vector<long long int> > precompute(1001,vector<long long int>(1001,1));
    precompute[0][0] = 1;
    for(int c=1;c<1001;c++)
    {
        for(int c2 = 0; c2 <= c;c2++)
        {
            precompute[c][c2] = (c2 == 0? 0: precompute[c-1][c2-1]) + (c2==c?0:precompute[c-1][c2]);
            precompute[c][c2]%=(long long)(1e9+7);
        }
    }
 
    int k;
    cin>>k;
    long long res = 1;
    long long tot = 0;
    while(k--)
    {
        int n;
        cin>>n;
        res *= precompute[tot+n-1][n-1];
        res%=(long long)(1e9+7);
        tot+=n;
    }
    cout<<res;
 
}