#pragma comment(linker, "/STACK:64000000")
#define _CRT_SECURE_NO_DEPRECATE
 
#ifdef ONLINE_JUDGE
    #define _SECURE_SCL 0
#else
    #define _GLIBCXX_DEBUG
#endif
 
#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <bitset>
#include <vector>
#include <string>
#include <cstdio>
#include <cassert>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
 
#define i64 "%I64d"
#define pb push_back
#define mp make_pair
#define sz(a) (int)a.size()
#define setval(a,key) memset(a, key, sizeof(a))
#define all(x) x.begin(), x.end()
#define sqr(x) ((x)*(x))
#define forn(i,n) for (i = 0; i < (n); i++)
#define curtime double(clock())/double(CLOCKS_PER_SEC)
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
const int dx[] = {-1,0,1,0,-1,-1,1,1,0};
const int dy[] = {0,1,0,-1,-1,1,1,-1,0};
 
const int inf = 1<<30;
const long long INF = 1ll<<62;
 
const double eps = 1e-9;
 
int main()
{
    // ios_base::sync_with_stdio(0);
    srand(time(0));
 
    #ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    #endif
    int n;
    cin>>n;
    int mini=inf;
    int indice_mini=-1;
    bool lol=false;
    for(int c=0;c<n;c++)
    {
        int z;
        cin>>z;
        if(z==mini)
            lol=true;
        if(z<mini)
        {
            lol=false;
            mini=z;
            indice_mini=c+1;
        }
    }
    if(lol)
        cout<<"Still Rozdil";
    else
        cout<<indice_mini;
    return 0;
}