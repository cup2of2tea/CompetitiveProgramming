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
#define MOD 10000009
 
#define FOREACH(i, n) for (typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
#define MEMSET(p, c) memset(p, c, sizeof(p))
using namespace std;
 
 
 
int main()
{
    #ifdef LOCAL
        ifstream in("input.txt");
        ofstream out("output2.txt");
    #endif
    int a,b,c;
    cin>>a>>b>>c;
    int m[1000001]={0};
    for(int c=1;c<1000001;c++)
        for(int c2=c;c2<1000001;c2+=c)
            m[c2]++;
    long long int sum=0;
    for(int a2=1;a2<=a;a2++)
        for(int b2=1;b2<=b;b2++)
            for(int c2=1;c2<=c;c2++)
            {
                sum+=m[a2*b2*c2];
                sum%=1073741824;
            }
    cout<<sum;
}