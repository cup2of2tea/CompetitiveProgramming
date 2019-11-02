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
#include <iomanip>
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
    vector<int> v(n);
    for(int c=0;c<n;c++)
        cin>>v[c];
    int maxi=0;
    for(int c=0;c<n;c++)
        for(int c2=c;c2<n;c2++)
        {
            int res=0;
            for(int c3=c;c3<=c2;c3++)
                res^=v[c3];
            maxi=max(maxi,res);
        }
    cout<<maxi<<endl;
}