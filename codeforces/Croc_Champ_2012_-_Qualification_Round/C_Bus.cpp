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
#include <iterator>
#define LOCAL
#ifdef ONLINE_JUDGE
#undef LOCAL
#endif
 
#ifdef LOCAL
#define cin in
#define cout out
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
 
bool comp(const pair<int,int> &p1,const pair<int,int> &p2)
{
    return p1.first<p2.first;
}
 
 
int main()
{
#ifdef LOCAL
    ifstream in("input.txt");
    ofstream out("output.txt");
#endif
    int n,m;
    cin>>n>>m;
    int time_act=0;
    vector<int> arrivee(n);
    for(int c=0;c<n;c+=m)
    {
        vector<pair<int,int> > v;
        int time,x;
        for(int c2=0;c2<m&&c2+c<n;c2++)
        {
            cin>>time>>x;
            v.push_back(make_pair(x,c2+c));
        }
        sort(v.begin(),v.end(),comp);
        time_act=max(time_act,time);
        for(int c2=0;c2<v.size();c2++)
        {
            int c3;
            arrivee[v[c2].second]=time_act+v[c2].first;
            for(c3=c2+1;c3<v.size()&&v[c3].first==v[c3-1].first;c3++){arrivee[v[c3].second]=time_act+v[c3].first;}
            c3--;
            int nb=c3-c2+1;
            time_act+=1+(nb/2);
            c2=c3;
        }
        time_act+=2*v.back().first;
    }
    for(int c=0;c<arrivee.size();c++)
        cout<<arrivee[c]<<" ";
}