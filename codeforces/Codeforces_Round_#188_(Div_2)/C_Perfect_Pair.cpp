#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <istream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <list>
#include <cstdio>
#include <set>
#include <iomanip>
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
 
#define COUT(s) cout<<"-----"<<s<<"-----"<<endl;
#endif
 
using namespace std;
 
 
 
int main(int argc,char **argv)
{
 
#ifdef LOCAL
    ifstream in("input.txt");
#endif
   long long x,y,m;
   cin>>x>>y>>m;
   long long res=0;
 
   while(max(x,y)<m)
   {
       if(x<=0&&y<=0)
       {
           cout<<-1;
           return 0;
       }
        if(x>y)
            swap(x,y);
        long long int diff=y-x;
        long long to_do=diff/y;
        to_do++;
        res+=to_do;
        x+=to_do*y;
 
   }
   cout<<res<<endl;
}