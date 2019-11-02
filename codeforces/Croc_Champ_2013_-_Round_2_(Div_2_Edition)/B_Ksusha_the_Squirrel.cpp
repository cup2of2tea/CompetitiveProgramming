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
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int act=0;
    for(int c=0;c<s.size();c++)
    {
        if(s[c]=='#')
        {
            act++;
        }
        else act=0;
        if(act>=k)
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
}