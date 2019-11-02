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
 
 
vector<int> execution(string s)
{
    int pointeur=0;
    int dx=1;
    vector<int> res(10,0);
    while(1)
    {
        bool warn=false;
        if(s[pointeur]=='<')
        {
            dx=-1;
            if(s[pointeur+dx]=='<'||s[pointeur+dx]=='>')
            {
                s=s.substr(0,pointeur)+s.substr(pointeur+1);
                warn=true;
            }
        }
        else if(s[pointeur]=='>')
        {
            dx=1;
            if(s[pointeur+dx]=='<'||s[pointeur+dx]=='>')
            {
                s=s.substr(0,pointeur)+s.substr(pointeur+1);
                warn=true;
            }
        }
        else
        {
            res[s[pointeur]-'0']++;
            if(s[pointeur]=='0')
            {
                s=s.substr(0,pointeur)+s.substr(pointeur+1);
                warn=true;
            }
            else s[pointeur]--;
        }
        if(!(warn&&dx==1))
            pointeur+=dx;
        if(pointeur>=s.size()||pointeur<0)
            break;
    }
    return res;
}
 
int main()
{
    #ifdef LOCAL
        ifstream in("input.txt");
        ofstream out("output.txt");
    #endif
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    for(int c=0;c<q;c++)
    {
        int a,b;
        cin>>a>>b;
        vector<int> res=execution(s.substr(a-1,b-a+1));
        for(int c2=0;c2<res.size();c2++)
            cout<<res[c2]<<" ";
        cout<<endl;
    }
}