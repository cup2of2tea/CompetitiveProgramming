#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <istream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <list>
#include <cstdio>
#include <set>
#include <iomanip>
#include <stack>
#include <ctime>
#include <climits>
#include <iterator>
#define LOCAL
#ifdef ONLINE_JUDGE
#define COUT(s)
#undef LOCAL
#endif
#ifdef LOCAL
#define cin in
#define COUT(s) cout<<"-----"<<s<<"-----"<<endl;
#endif
 
using namespace std;
 
 
int main(int argc,char **argv)
{
#ifdef LOCAL
    ifstream in("input.txt");
#endif
    int n,m,k;
    cin>>m>>n>>k;
    vector<long long int> init(m);
    vector<long long int> intervalles(m+1,0);
    vector<long long int> intervallesf(n+1,0);
    vector<int> l(n),r(n),d(n);
    for(int c=0;c<m;c++)
        cin>>init[c];
    for(int c=0;c<n;c++)
    {
        cin>>l[c]>>r[c]>>d[c];
        l[c]--;
        r[c]--;
    }
    for(int c=0;c<k;c++)
    {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        intervallesf[x]++;
        intervallesf[y+1]--;
    }
    for(int c=1;c<n;c++)
    {
        intervallesf[c]+=intervallesf[c-1];
    }
    for(int c=0;c<n;c++)
    {
        intervalles[l[c]]+=intervallesf[c]*d[c];
        intervalles[r[c]+1]-=intervallesf[c]*d[c];
    }
    for(int c=1;c<m;c++)
    {
        intervalles[c]+=intervalles[c-1];
    }
    for(int c=0;c<m;c++)
    {
        long long z=init[c]+intervalles[c];
        cout<<z<<" ";
    }
    return 0;
}