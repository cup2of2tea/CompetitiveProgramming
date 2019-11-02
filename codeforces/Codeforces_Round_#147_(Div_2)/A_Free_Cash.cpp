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
    int nb;
    cin>>nb;
    int prec1=-1,prec2=-1;
    int act=0;
    int maxi=1;
    for(int c=0;c<nb;c++)
    {
        int a,b;
        cin>>a>>b;
        if(a==prec1&&b==prec2)
            act++;
        else act=1;
        prec1=a;
        prec2=b;
        maxi=max(maxi,act);
    }
    cout<<maxi;
}