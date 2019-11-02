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
    double S;
    cin>>S;
    double a,b,c;
    cin>>a>>b>>c;
    double tot=a+b+c+0.00000001;
    cout<<setprecision(16)<<fixed<<S*a/tot<<" "<<S*b/tot<<" "<<S*c/tot;
}