#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <ctime>
#include <iterator>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
 
int main()
{
ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
#define cin in
    ifstream in("input.txt");
#endif // ONLINE_JUDGE
    int n;
    cin>>n;
    vector<int> v(n);
    vector<long long> tot(n,0);
    for(int c=0;c<n;c++)
    {
        cin>>v[c];
        tot[c]+=v[c];
        if(c>0) tot[c]+=tot[c-1];
    }
    if(tot[n-1]%3!=0)
    {
        cout<<0;
        return 0;
    }
    long long int act = 0;
    long long int res = 0;
    for(int c=0;c+1<n;c++)
    {
        if(tot[c]==2*tot[n-1]/3)
        {
            res+=act;
        }
        if(tot[c]==tot[n-1]/3)
        {
            act++;
        }
    }
    cout<<res;
}