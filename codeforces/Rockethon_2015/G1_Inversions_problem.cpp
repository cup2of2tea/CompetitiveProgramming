#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <set>
#include <iterator>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <list>
#include <stack>
#include <limits.h>
#define ll long long
using namespace std;
 
long long bla=0;
long long possibilites=0;
 
void bourrin(vector<int> &p,int k)
{
    if(k==0)
    {
        possibilites++;
        for(int c=0;c<p.size();c++)
        {
            for(int c2=c+1;c2<p.size();c2++)
            {
                if(p[c]>p[c2]) bla++;
            }
        }
        return;
    }
    for(int c=0;c<p.size();c++)
    {
        for(int c2=c+1;c2<=p.size();c2++)
        {
            reverse(p.begin()+c,p.begin()+c2);
            bourrin(p,k-1);
            reverse(p.begin()+c,p.begin()+c2);
        }
    }
}
 
 
int main()
{
    ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    #define cin in
    ifstream in("input.txt");
#endif // ONLINE_JUDGE
    int n,k;
    cin>>n>>k;
    vector<int> p(n);
    for(int c=0;c<n;c++) cin>>p[c];
    bourrin(p,k);
    cout<<fixed<<setprecision(10)<<static_cast<double>(bla)/static_cast<double>(possibilites);
}