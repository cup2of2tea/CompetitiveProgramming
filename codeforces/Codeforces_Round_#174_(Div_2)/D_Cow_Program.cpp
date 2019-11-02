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
 
vector<int> a;
 
map<long long int,long long int> m1;
 
long long step2(int x);
 
long long step1(int x)
{
    if(x>a.size()||x<=0)
        return 0;
    if(m1.find(x)!=m1.end()&&(x!=1||m1[1]!=0))
    {
        return m1[x];
    }
    m1[x]=-1;
    long long int z=step2(x+a[x-1]);
    if(z!=-1)
        m1[x]=a[x-1]+z;
    return m1[x];
}
 
map<long long int,long long int> m2;
 
long long step2(int x)
{
    if(x>a.size()||x<=0)
        return 0;
    if(m2.find(x)!=m2.end()&&(x==1||m2[1]!=0))
    {
        return m2[x];
    }
    m2[x]=-1;
    long long z=step1(x-a[x-1]);
    if(z!=-1)
        m2[x]=a[x-1]+z;
    return m2[x];
}
 
 
int main(int argc,char **argv)
{
#ifdef LOCAL
    ifstream in("input.txt");
    ofstream out("output.txt");
#endif
    int n;
    cin>>n;
    a.resize(n);
    for(int c=0;c<n;c++)
    {
        cin>>a[c+1];
    }
    for(int c=1;c<n;c++)
    {
        a[0]=c;
        m1[1]=0;
        m2[1]=0;
        cout<<step1(1)<<endl;
    }
}