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
#include <iterator>
#define MOD 1000000007
 
#define LOCAL
#ifdef ONLINE_JUDGE
#undef LOCAL
#endif
 
#ifdef LOCAL
#define cin in
#endif
 
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
    for(long long unsigned c=0; c<v.size(); c++)
    {
        m[v[c]]++;
        if(m[v[c]]-1)
            distinct=false;
    }
    for(typename map<T2,T>::iterator it=m.begin(); it!=m.end(); it++)
        total/=fac<T,T>(it->second);
    return total;
}
 
template <typename  T,typename  T2,typename  T3>
T nb_permutations(vector<T2> v,T3 mod)
{
    T total=fac<T,T,T3>(v.size(),mod);
    map<T2,T> m;
    bool distinct=true;
    for(long long unsigned c=0; c<v.size(); c++)
    {
        m[v[c]]++;
        if(m[v[c]]-1)
            distinct=false;
    }
    for(typename map<T2,T>::iterator it=m.begin(); it!=m.end(); it++)
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
 
 
 
int main()
{
#ifdef LOCAL
    ifstream in("input.txt");
#endif
    int tot=0;
    bool visites[200][200]={false};
    for(int c=0;c<200;c++)
        for(int c2=0;c2<200;c2++)
            visites[c][c2]=false;
    int n;
    cin>>n;
    vector<vector<int> > v(n,vector<int>(n));
    for(int c=0;c<n;c++)
        for(int c2=0;c2<n;c2++)
            cin>>v[c][c2];
    for(int c=0;c<n;c++)
    {
            if(!visites[c][c])
                tot+=v[c][c];
            visites[c][c]=true;
            if(!visites[c][n-c-1])
                tot+=v[c][n-c-1];
            visites[c][n-c-1]=true;
            if(!visites[c][(n-1)/2])
                tot+=v[c][(n-1)/2];
            visites[c][(n-1)/2]=true;
            if(!visites[(n-1)/2][c])
                tot+=v[(n-1)/2][c];
            visites[(n-1)/2][c]=true;
    }
    cout<<tot;
}