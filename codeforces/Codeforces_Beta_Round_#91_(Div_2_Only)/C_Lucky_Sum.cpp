#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <map>
#include <cstdio>
 
 
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
    if(a==0||b==0)
        return 0;
    if(a>b)
        swap(a,b);
    if(a==b||a==1)
        return a;
    return pgcd(a,b-a);
}
 
long long int next(long long int n)
{
    stringstream ss;
    ss<<n;
    string s;
    ss>>s;
    int c;
    for(c=s.size()-1;c>=0&&s[c]=='7';c--)
    {
        s[c]='4';
    }
    if(c==-1)
    {
        s='4'+s;
    }
    else
    {
        s[c]='7';
    }
    stringstream ss2;
    ss2<<s;
    ss2>>n;
    return n;
}
 
int main()
{
 
    #ifdef LOCAL
    ifstream in("input.txt");
    #endif
    long long int a,b;
    cin>>a>>b;
    long long int act=4;
    long long int total=0;
    while(act<a)
        act=next(act);
    long long int c=a;
    while(c<=b)
    {
        total+=act*(min(act-c+1,b-c+1));
        c=act+1;
        act=next(act);
    }
    cout<<total;
}