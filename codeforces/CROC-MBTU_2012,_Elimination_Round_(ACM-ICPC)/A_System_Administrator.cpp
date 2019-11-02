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
    int sum1[2]={0};
    int sum2[2]={0};
    for(int c=0;c<n;c++)
    {
        int a,b,d;
        cin>>a>>b>>d;
        sum1[a-1]+=b;
        sum2[a-1]+=d;
    }
    for(int c=0;c<2;c++)
        cout<<(sum1[c]>=sum2[c]?"LIVE":"DEAD")<<endl;
 
}