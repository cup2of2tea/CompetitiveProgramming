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
 
map<string,bool> m;
 
bool dp(string de,int nb_1,string to)
{
    cout<<de<<endl;
    if(de==to)
    {
        return true;
    }
    if(m.find(de)!=m.end())
        return false;
    if(dp(de+(char)(nb_1%2+'0'),nb_1%2+nb_1,to))
        return true;
    if(dp(de.substr(1),nb_1-(de[0]=='1'?1:0),to))
        return true;
    m[de]=false;
    return false;
}
 
 
int main(int argc,char **argv)
{
#ifdef LOCAL
    ifstream in("input.txt");
#endif
    int n,m,k;
    cin>>n>>m>>k;
    map<int,int> Alice;
    map<int,int> Bob;
    set<int> type;
    for(int c=0;c<n;c++)
    {
        int z;
        cin>>z;
        type.insert(z);
        Alice[z]++;
    }
    for(int c2=0;c2<m;c2++)
    {
        int z;
        cin>>z;
        type.insert(z);
        Bob[z]++;
    }
    int res=0;
    for(set<int>::iterator it=type.begin();it!=type.end();it++)
    {
        res+=Alice[*it]-Bob[*it];
        res=max(res,0);
    }
    cout<<(res>0?"YES":"NO");
}