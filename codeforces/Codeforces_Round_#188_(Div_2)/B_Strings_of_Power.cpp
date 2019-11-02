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
   string s;
   getline(cin,s);
   string act="";
   int heavy=0;
   long long res=0;
   for(int c=0;c<s.size();c++)
   {
        act=act+s[c];
        if(act.size()>5)
        {
            act=act.substr(1);
        }
        if(act=="heavy")
            heavy++;
        if(act=="metal")
            res+=heavy;
   }
   cout<<res;
}