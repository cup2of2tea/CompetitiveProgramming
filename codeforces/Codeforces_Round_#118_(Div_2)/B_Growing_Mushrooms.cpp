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
 
typedef struct score
{
    score(){}
    score(int a,double b):indice(a),total(b){}
    int indice;
    double total;
};
 
bool comparaison(const score &s1,const score &s2)
{
    if(s1.total==s2.total)
        return s1.indice<s2.indice;
    return s1.total>s2.total;
}
 
 
int main()
{
#ifdef LOCAL
    ifstream in("input.txt");
#endif
    double n,t1,t2,k;
    cin>>n>>t1>>t2>>k;
    vector<score> v;
    for(int c=0;c<n;c++)
    {
        double a,b;
        cin>>a>>b;
        v.push_back(score(c,max((double)(a*t1*(100-k)/100.0)+(double)(b*t2),(double)(b*t1*(100-k)/100.0)+(double)(a*t2))));
    }
    sort(v.begin(),v.end(),comparaison);
    for(int c=0;c<v.size();c++)
        cout<<v[c].indice+1<<" "<<setprecision(2)<<fixed<<v[c].total<<endl;
}