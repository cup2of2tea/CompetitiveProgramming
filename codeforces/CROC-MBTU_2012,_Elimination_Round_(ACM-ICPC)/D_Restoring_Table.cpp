#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <cstdio>
#include <set>
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
#define COUT(s) cout<<"-----"<<s<<endl;
#endif
 
#define FOREACH(i, n) for (typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
#define MEMSET(p, c) memset(p, c, sizeof(p))
using namespace std;
 
 
 
int main()
{
    #ifdef LOCAL
        ifstream in("input.txt");
        ofstream out("output.txt");
    #endif
    int n;
    cin>>n;
    vector<vector<int> > v(n,vector<int> (n));
    for(int c=0;c<n;c++)
    {
        for(int c2=0;c2<n;c2++)
        {
            cin>>v[c][c2];
        }
    }
    vector<vector<short> > res(n,vector<short>(30,-1));
    for(int c=0;c<n;c++)
    {
        for(int c2=c+1;c2<n;c2++)
        {
            for(int c3=0;c3<30;c3++)
            {
                if(v[c][c2]&(1<<c3))
                {
                    res[c][c3]=res[c2][c3]=1;
                }
            }
        }
    }
    for(int c=0;c<n;c++)
    {
        long long int a=0;
        for(int c3=0;c3<30;c3++)
            {
                if(res[c][c3]==1)
                {
                    a+=(1<<c3);
                }
            }
        cout<<a<<" ";
    }
}