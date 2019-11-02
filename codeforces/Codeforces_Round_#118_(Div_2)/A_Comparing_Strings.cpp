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
    string s1,s2;
    cin>>s1>>s2;
    if(s1.size()!=s2.size()){cout<<"NO"; return 0;}
    for(int c=0;c<s1.size();c++)
        if(s1[c]!=s2[c])
        {
            for(int c2=c+1;c2<s1.size();c2++)
                if(s1[c2]!=s2[c2])
                {
                    swap(s1[c],s1[c2]);
                    if(s1==s2)
                    {
                        cout<<"YES";
                    }
                    else cout<<"NO";
                    return 0;
                }
            cout<<"NO";
            return 0;
        }
    cout<<"YES";
}