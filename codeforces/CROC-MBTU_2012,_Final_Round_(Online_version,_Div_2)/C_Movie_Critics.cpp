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
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    vector<int> bonus(k+1,0);
    for(int c=0;c<n;c++)
        cin>>v[c];
    for(int c=0;c<n-1;c++)
    {
        if(v[c+1]!=v[c])
        {
            int c2=c+2;
            while(c2<n&&v[c2]==v[c+1])c2++;
            bonus[v[c+1]]+=2;
            if(c2==n)
                bonus[v[c+1]]--;
            if(c2<n&&v[c2]!=v[c])
                bonus[v[c+1]]--;
        }
    }
    bonus[v[0]]++;
    int indice_maxi=1;
    for(int c=2;c<k+1;c++)
        if(bonus[indice_maxi]<bonus[c])
            indice_maxi=c;
    cout<<indice_maxi;
}