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
#include <fstream>
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
 
#ifndef ONLINE_JUDGE
    #define cin in
    #define cout out
#endif
 
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
    srand(time(0));
 
    #ifndef ONLINE_JUDGE
    ifstream cin("a.in");
    ofstream cout("a.out");
    #endif
    long long int n;
    cin>>n;
    if(n==0)
    {
        cout<<4<<" "<<4<<endl;
    }
    vector<long long int> diviseurs;
    for(long long int c=1;c<=sqrt(n);c++)
    {
        if(n%c==0)
        {
            diviseurs.push_back(c);
            if(n/c!=c)
            diviseurs.push_back(n/c);
        }
    }
    long long int mini=INF;
    long long int maxi=0;
    for(long long int c=0;c<diviseurs.size();c++)
    {
        for(long long int c2=0;c2<diviseurs.size();c2++)
        {
            if((n/diviseurs[c])%diviseurs[c2]!=0)
                continue;
            long long int c3=(n/diviseurs[c])/diviseurs[c2];
            maxi=max(maxi,(diviseurs[c]+1)*(diviseurs[c2]+2)*(c3+2)-n);
            mini=min(mini,(diviseurs[c]+1)*(diviseurs[c2]+2)*(c3+2)-n);
        }
    }
    cout<<mini<<" "<<maxi;
    return 0;
}