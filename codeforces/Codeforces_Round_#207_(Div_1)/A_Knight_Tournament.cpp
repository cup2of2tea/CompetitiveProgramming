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
 
 
int getNext(vector<int> &next,int z)
{
    if(next[z]>=next.size()) return next[z];
    if(next[z]==z) return z;
    return (next[z]=getNext(next,next[z]));
}
 
 
 
int main()
{
 
    ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    #define cin in
    ifstream in("input.txt");
#endif // ONLINE_JUDGE
    int n,m;
    cin>>n>>m;
    vector<int> next(n+1);
    for(int c=0;c<n+1;c++)
        next[c]=c;
    vector<int> res(n+1,0);
    for(int c=0;c<m;c++)
    {
        int l,r,x;
        cin>>l>>r>>x;
        int dep=getNext(next,l);
        while(dep<=r)
        {
           if(dep==x)
           {
               dep++;
           }
           else
           {
                res[dep]=x;
                next[dep]=dep+1;
           }
           if(dep>r) break;
           dep=getNext(next,dep);
        }
    }
    copy(res.begin()+1,res.end(),ostream_iterator<int>(cout," "));
}