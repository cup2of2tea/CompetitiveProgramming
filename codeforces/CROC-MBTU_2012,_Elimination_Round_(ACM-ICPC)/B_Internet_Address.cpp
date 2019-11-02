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
 
#define FOREACH(i, n) for (typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
#define MEMSET(p, c) memset(p, c, sizeof(p))
using namespace std;
 
 
 
int main()
{
    #ifdef LOCAL
        ifstream in("input.txt");
        ofstream out("output.txt");
    #endif
    string s;
    cin>>s;
    string res="";
    if(s[0]=='h')
    {
        res=res+s.substr(0,4)+"://";
        s=s.substr(4);
    }
    else
    {
        res=res+s.substr(0,3)+"://";
        s=s.substr(3);
    }
    res=res+s[0];
    s=s.substr(1);
    while(s[0]!='r'||s[1]!='u')
    {
        res=res+s[0];
        s=s.substr(1);
    }
    res=res+".ru";
    s=s.substr(2);
    if(s.size()!=0)
    {
        res=res+"/"+s;
    }
    cout<<res;
}