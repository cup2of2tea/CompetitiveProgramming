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
    int n,d;
    cin>>n>>d;
    vector<int> v(n);
    for(int c=0;c<n;c++)
        cin>>v[c];
    int droite=1;
    long long res=0;
    vector<long long> fac(100001,0);
    fac[0]=0;
    for(int c=1;c<100001;c++)
        fac[c]=fac[c-1]+c;
    for(int c=0;c<n;c++)
    {
        while(droite<n&&v[droite]-v[c]<=d)
            droite++;
        droite--;
        if(droite-c>=2)
            res+=fac[droite-c-1];
    }
    cout<<res;
 
}