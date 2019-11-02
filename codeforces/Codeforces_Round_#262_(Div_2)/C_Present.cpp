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
#define int long long
bool possible(int w,int nbOps,int finalHeight,vector<int> &flowers)
{
 
    int act = 0;
    vector<int> decrement(flowers.size(),0);
    for(int c=0;nbOps>=0&&c<flowers.size();c++)
    {
 
        act-=decrement[c];
        if(finalHeight>flowers[c]+act)
        {
            nbOps-=finalHeight-(flowers[c]+act);
            if(c+w < decrement.size())
                decrement[c+w]+=finalHeight-(flowers[c]+act);
            act=finalHeight-flowers[c];
        }
    }
    return nbOps >= 0;
}
#undef int
int main()
{
ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
#define cin in
    ifstream in("input.txt");
#endif // ONLINE_JUDGE
#define int long long
 
    int n,m,w;
    cin>>n>>m>>w;
    vector<int> v(n);
    for(int c=0;c<n;c++) cin>>v[c];
    long long gauche = 0, droite = 10000000000;
    while(gauche!=droite)
    {
        long long mid = (gauche+droite+1LL)/2LL;
        if(possible(w,m,mid,v))
        {
            gauche = mid;
        }
        else
        {
            droite = mid-1;
        }
    }
    cout<<gauche;
}