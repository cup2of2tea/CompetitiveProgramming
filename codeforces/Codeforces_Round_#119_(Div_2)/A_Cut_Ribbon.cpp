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
#define LOCAL
#ifdef ONLINE_JUDGE
#undef LOCAL
#endif
 
#ifdef LOCAL
#define cin in
#endif
#define FOREACH(i, n) for (typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
#define MEMSET(p, c) memset(p, c, sizeof(p))
 
 
using namespace std;
 
 
 
int main()
{
#ifdef LOCAL
    ifstream in("input.txt");
#endif
    int N;
    int a,b,c;
    int maxi=-1;
    cin>>N>>a>>b>>c;
    for(int c1=0;c1*a<=N;c1++){
        for(int c2=0;c2*b<=N-c1*a;c2++)
                if((N-(c1*a+c2*b))>=0&&(N-(c1*a+c2*b))%c==0)
                    maxi=max(maxi,c1+c2+(N-(c1*a+c2*b))/c);}
    cout<<maxi;
}