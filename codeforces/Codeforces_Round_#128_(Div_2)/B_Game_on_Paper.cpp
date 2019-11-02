#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <map>
#include <cstdio>
#include <set>
#include <ctime>
#include <queue>
#include <climits>
#include <iomanip>
#include <iterator>
#include <stack>
#define LOCAL
#ifdef ONLINE_JUDGE
#undef LOCAL
#endif
 
 
 
#ifdef LOCAL
#define cin in
#endif
#define FOREACH(i, n) for (typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
 
using namespace std;
 
 
int main()
{
#ifdef LOCAL
    ifstream cin("input.txt");
#endif
    int n,m;
    cin>>n>>m;
    vector<vector<int> > v(n,vector<int>(n,0));
    for(int cas=0;cas<m;cas++)
    {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        v[a][b]=1;
        for(int c=max(a-2,0);c<=min(a+2,n-3);c++)
        {
            for(int c2=max(b-2,0);c2<=min(b+2,n-3);c2++)
            {
                for(int c3=0;c3<3;c3++)
                {
                    for(int c4=0;c4<3;c4++)
                    {
                        if(v[c+c3][c2+c4]==0)
                            goto end;
                    }
                }
                cout<<cas+1;
                return 0;
                end:;
            }
        }
    }
    cout<<-1;
}