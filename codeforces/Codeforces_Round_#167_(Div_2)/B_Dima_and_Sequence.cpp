#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <istream>
#include <cmath>
#include <algorithm>
#include <queue>
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
 
 
map<long long int,long long int> m;
 
long long process(long long a)
{
    if(m.find(a)!=m.end())
        return m[a];
    m[a]=process(a/2)+(a%2);
    return m[a];
}
 
int main(int argc,char **argv)
{
#ifdef LOCAL
    ifstream in("input.txt");
    ofstream out("output.txt");
#endif
    int n;
    cin>>n;
    m[0]=0;
    map<long long,long long int> count;
    for(int c=0;c<n;c++)
    {
        long long int z;
        cin>>z;
        count[process(z)]++;
    }
    long long res=0;
    for(map<long long,long long int>::iterator it=count.begin();it!=count.end();it++)
    {
        res+=(it->second)*(it->second-1)/2;
    }
    cout<<res;
}