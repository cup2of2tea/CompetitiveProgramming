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
 
int main()
{
    #ifdef LOCAL
        ifstream in("input.txt");
        ofstream out("output.txt");
    #endif
    int na,ma,nb,mb;
    cin>>na>>ma;
    vector<string> v(na);
    for(int c=0;c<v.size();c++)
        cin>>v[c];
    cin>>nb>>mb;
    vector<string> v2(nb);
    for(int c=0;c<v2.size();c++)
        cin>>v2[c];
    long long maxi=0;
    int resx=0,resy=0;
    for(int c=-max(nb,na);c<=max(nb,na);c++)
        for(int c2=-max(mb,ma);c2<=max(mb,ma);c2++)
        {
            int temp=0;
            for(int c3=max(-c,0);c3<na&&c3+c<nb;c3++)
            {
                for(int c4=max(-c2,0);c4<ma&&c4+c2<mb;c4++)
                {
                    if(c3+c>=0&&c4+c2>=0)
                        temp+=((v[c3][c4]-'0')*(v2[c3+c][c4+c2]-'0'));
                }
            }
            if(temp>maxi)
            {
                resx=c;
                resy=c2;
                maxi=temp;
            }
        }
    cout<<resx<<" "<<resy;
}