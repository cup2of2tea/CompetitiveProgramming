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
#define COUT(s) cout<<"----"<<s<<"----"<<endl
#endif
#ifndef LOCAL
#define COUT(s);
#endif
#define FOREACH(i, n) for (typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
 
using namespace std;
 
 
int main()
{
#ifdef LOCAL
    ifstream cin("input.txt");
#endif
    string s;
    getline(cin,s);
    string res="";
    int act=0;
    for(int c=0;c<s.size();c++)
    {
        if(c+2<s.size()&&s[c]=='W'&&s[c+1]=='U'&&s[c+2]=='B')
        {
            if(act)
                res=res+' ';
            act=0;
            c+=2;
            continue;
        }
        res=res+s[c];
        act=1;
    }
    cout<<res;
}