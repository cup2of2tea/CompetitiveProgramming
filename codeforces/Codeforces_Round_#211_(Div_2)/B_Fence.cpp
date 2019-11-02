#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cmath>
 
using namespace std;
 
 
 
int main()
{
#ifndef ONLINE_JUDGE
//    #define cin in
    ifstream in("input.txt");
#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    int indice=0;
    vector<int> sum(n);
    for(int c=0;c<n;c++)
    {
        cin>>sum[c];
        if(c>0) sum[c]+=sum[c-1];
    }
    int mini=1000000000;
    for(int c=k-1;c<n;c++)
    {
        if(c==k-1)
        {
            if(mini>sum[c])
            {
                mini=min(mini,sum[c]);
                indice=c-k+1;
            }
        }
        else if(mini>min(mini,sum[c]-sum[c-k]))
        {
             mini=min(mini,sum[c]-sum[c-k]);
             indice=c-k+1;
        }
    }
    cout<<indice+1;
}