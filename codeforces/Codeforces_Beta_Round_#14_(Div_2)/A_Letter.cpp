#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <map>
 
#ifdef LOCAL
#define cin in
#endif
 
#define FOREACH(i, n) for (typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
#define MEMSET(p, c) memset(p, c, sizeof(p))
 
using namespace std;
 
template < class T,class T2 >
T2 fac(T n)
{
    return n<2?1:fac<T,T2>(n-1)*n;
}
 
template <class T>
T nb_combinaisons(T k,T n)
{
    if(n<k)
        return nb_combinaisons<T>(n,k);
    return fac<T,long long int>(n)/(fac<T,long long int>(n-k)*fac<T,long long int>(k));
}
 
string itoa_2(long long int n)
{
    string s;
    stringstream ss;
    ss<<n;
    ss>>s;
    while(s.size()!=9)
        s='0'+s;
    return s;
}
 
int pgcd (int a,int b)
{
    if(a>b)
        swap(a,b);
    if(a==b||a==1)
        return a;
    return pgcd(a,b-a);
}
 
int main()
{
    #ifdef LOCAL
        ifstream in("input.txt");
    #endif
 
   int n,m;
   cin>>n>>m;
   vector<string> v(n);
   for(int c=0;c<n;c++)
    cin>>v[c];
    int xmin=10000000;
    int ymin=10000000;
    int xmax=-1;
    int ymax=-1;
   for(int c=0;c<v.size();c++)
    for(int c2=0;c2<v[c].size();c2++)
        if(v[c][c2]=='*')
        {
            xmin=min(c,xmin);
            ymin=min(c2,ymin);
            xmax=max(c,xmax);
            ymax=max(c2,ymax);
        }
    for(int c=0;c<v.size();c++)
    {
        if(xmin>c||xmax<c)
            continue;
        for(int c2=0;c2<v[c].size();c2++)
        {
            if(ymin>c2||ymax<c2)
                continue;
            cout<<v[c][c2];
        }
        cout<<endl;
    }
}