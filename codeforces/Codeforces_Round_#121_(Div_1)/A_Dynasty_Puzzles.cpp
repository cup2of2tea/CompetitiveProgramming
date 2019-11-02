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
    int n;
    cin>>n;
    vector<string> v(n);
    for(int c=0;c<n;c++)
    {
        cin>>v[c];
    }
    vector<vector<int > > dp(26,vector<int>(26));
    for(int c=0;c<26;c++)
        for(int c2=0;c2<26;c2++)
            dp[c][c2]=0;
    int maxi=0;
    for(int c=0;c<n;c++)
    {
         int truc=v[c][v[c].size()-1]-'a';
        for(int c2=0;c2<='z'-'a';c2++)
        {
            if(truc>25||truc<0)
                break;
            if(dp[v[c][0]-'a'][c2]!=0)
                dp[truc][c2]=max((int)v[c].size()+dp[v[c][0]-'a'][c2],dp[truc][c2]);
        }
        dp[truc][v[c][0]-'a']=max(dp[truc][v[c][0]-'a'],(int)v[c].size());
    }
    for(int c=0;c<26;c++)
        maxi=max(dp[c][c],maxi);
    cout<<maxi;
}