#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <set>
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
    int n,m,k;
    cin>>n>>m>>k;
    int res=0;
    vector<int> v(n);
    for(int c=0;c<n;c++)
    {
        cin>>v[c];
    }
    sort(v.begin(),v.end());
    for(int c=0;c<v.size();c++)
    {
        if(v[c]==1)
        {
            if(m) m--;
            else res++;
        }
        else
        {
            if(m) m--;
            else if(k) k--;
            else res++;
        }
    }
    cout<<res<<endl;
}