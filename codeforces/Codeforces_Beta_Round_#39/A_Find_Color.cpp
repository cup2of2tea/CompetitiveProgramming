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
    int x,y;
    cin>>x>>y;
    int z=sqrt((double)(x*x+y*y));
    if(z*z<x*x+y*y&&(z+1)*(z+1)>x*x+y*y)
    {
        if((((x>0&&y>0)||(x<0&&y<0))&&z%2==0)||(((x<0&&y>0)||(x>0&&y<0))&&z%2==1))
            cout<<"black";
        else cout<<"white";
    }
    else
        cout<<"black";
}