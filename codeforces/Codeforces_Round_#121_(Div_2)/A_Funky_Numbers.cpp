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
#define MEMSET(p, c) memset(p, c, sizeof(p))
 
 
 
using namespace std;
 
int main()
{
#ifdef LOCAL
    ifstream in("input.txt");
#endif
    long long int n;
    cin>>n;
    n*=2;
    for(long long int c=1;n>=0;c++)
    {
        n-=c*2;
        if(n==0)
            break;
        long long int n2=sqrt(n);
        if(n2*(n2+1)==n)
        {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
}