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
//#define cout out
#define COUT(s) cout<<"-----"<<s<<endl;
#endif
#define MOD 10000009
 
#define FOREACH(i, n) for (typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
#define MEMSET(p, c) memset(p, c, sizeof(p))
using namespace std;
 
struct point
{
    point(){}
    point(double a,double b,double c):x(a),y(b),z(c){}
    double x;
    double y;
    double z;
};
 
int main()
{
    #ifdef LOCAL
        ifstream in("input.txt");
        ofstream out("output.txt");
    #endif
    int n;
    cin>>n;
    if(n%2==1)
    {
        cout<<-1;
        return 0;
    }
    for(int c=0;c<n/2;c++)
    {
        cout<<c*2+2<<" "<<c*2+1<<" ";
    }
}