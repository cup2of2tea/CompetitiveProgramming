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
#include <climits>
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
 
template < typename  T,typename  T2 >
T2 fac(T n)
{
    return n<2?1:fac<T,T2>(n-1)*n;
}
 
template < typename  T,typename  T2,typename  T3>
T2 fac(T n, T3 mod)
{
    return n<2?1:(fac<T,T2,T3>(n-1,mod)*n)%mod;
}
template <typename  T>
T nb_combinaisons(T k,T n)
{
    if(n<k)
        return nb_combinaisons<T>(n,k);
    return fac<T,long long int>(n)/(fac<T,long long int>(n-k)*fac<T,long long int>(k));
}
 
template <typename T,typename  T2>
T nb_permutations(vector<T2> v)
{
    T total=fac<T,T>(v.size());
    map<T2,T> m;
    bool distinct=true;
    for(long long unsigned c=0;c<v.size();c++)
    {
        m[v[c]]++;
        if(m[v[c]]-1)
            distinct=false;
    }
    for(typename map<T2,T>::iterator it=m.begin();it!=m.end();it++)
        total/=fac<T,T>(it->second);
    return total;
}
 
template <typename  T,typename  T2,typename  T3>
T nb_permutations(vector<T2> v,T3 mod)
{
    T total=fac<T,T,T3>(v.size(),mod);
    map<T2,T> m;
    bool distinct=true;
    for(long long unsigned c=0;c<v.size();c++)
    {
        m[v[c]]++;
        if(m[v[c]]-1)
            distinct=false;
    }
    for(typename map<T2,T>::iterator it=m.begin();it!=m.end();it++)
        total/=fac<T,T>(it->second);
    return total%mod;
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
    if(a==0)
        return b;
    if(b==0)
        return a;
    return pgcd(b,a%b);
}
 
string conversion(int n,int base)
{
    string res="";
    while(n!=0)
    {
        res=((char)('0'+n%base))+res;
        n/=base;
    }
    return res;
}
 
string min2(string s1,string s2)
{
    for(int c=0;c<min(s1.size(),s2.size());c++)
        if(s1[c]!=s2[c])
            if(s1[c]<s2[c])
                return s1;
            else return s2;
    return (s1.size()<s2.size()?s1:s2);
}
 
int main()
{
#ifdef LOCAL
    ifstream in("input.txt");
#endif
    string s;
    int n;
    cin>>s>>n;
    string mini="";
    for(int c=0;c<200;c++)
        mini=mini+'z';
    for(int c=0;c<n;c++)
    {
        string s2;
        cin>>s2;
        if(s2.size()<s.size())
            continue;
        if(s2.substr(0,s.size())==s)
            mini=min2(mini,s2);
    }
    if(mini.size()>101)
        cout<<s;
    else cout<<mini;
}