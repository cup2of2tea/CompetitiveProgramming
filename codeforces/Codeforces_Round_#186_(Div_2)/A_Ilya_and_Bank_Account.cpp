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
 
long long to_long_long(string s)
{
    long long res=0;
    for(int c=0;c<s.size();c++)
    {
        if(s[c]=='-')
            continue;
        res*=10;
        res+=s[c]-'0';
    }
    return res*(s[0]=='-'?-1:1);
}
 
 
int main(int argc,char **argv)
{
#ifdef LOCAL
    ifstream in("input.txt");
#endif
        string s;
        cin>>s;
        stringstream ss(s);
        long long a=to_long_long(s),b=to_long_long(s.substr(0,s.size()-1)),c=to_long_long((s.substr(0,s.size()-2)+s.substr(s.size()-1)));
        cout<<max(a,max(b,c));
}