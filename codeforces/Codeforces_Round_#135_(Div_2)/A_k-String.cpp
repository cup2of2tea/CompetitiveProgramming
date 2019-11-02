#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <ctime>
#define FOREACH(i, n) for (typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
#define MEMSET(p, c) memset(p, c, sizeof(p))
 
using namespace std;
 
 
int main()
{
//#ifndef ONLINE_JUDGE
//#define cin in
//    ifstream in("input.txt");
//#endif
    string s;
    int k;
    cin>>k;
        cin>>s;
 
    sort(s.begin(),s.end());
    string res="";
    if(s.size()%k!=0)
    {
        cout<<-1;
        return 0;
    }
    for(int c=0;c<k;c++)
    {
        for(int c2=c;c2<s.size();c2+=k)
        {
            if(c>0&&s[c2-1]!=s[c2])
            {
                cout<<-1;
                return 0;
            }
            res=res+s[c2];
        }
    }
    cout<<res;
}