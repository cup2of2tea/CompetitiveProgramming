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
 
typedef struct phonebook
{
    int girls;
    int taxi;
    int pizzas;
};
bool comp(const pair<string,int> &p1,const pair<string,int> &p2)
{
    return p1.second<p2.second;
}
 
int main()
{
#ifdef LOCAL
    ifstream in("input.txt");
#endif
    map<pair<string,int> ,phonebook> m;
    int nb_friends;
    cin>>nb_friends;
    int maxi_girls=-1,maxi_pizzas=-1,maxi_taxi=-1;
    for(int c=0;c<nb_friends;c++)
    {
        int nb_num;
        string ami;
        cin>>nb_num>>ami;
        for(int c2=0;c2<nb_num;c2++)
        {
            string s;
            cin>>s;
            char prec=0;
            bool taxi=true,pizza=true;
            for(int c=0;c<s.size();c++)
                if(s[c]=='-')
                    continue;
                else if(c==0)
                {
                    prec=s[c];
                }
                else
                {
                    if(prec<=s[c])
                        pizza=false;
                    if(prec!=s[c])
                        taxi=false;
                    prec=s[c];
                }
            if(taxi)
                m[make_pair(ami,c)].taxi++;
            else if(pizza)
                m[make_pair(ami,c)].pizzas++;
            else m[make_pair(ami,c)].girls++;
        }
        maxi_girls=max(maxi_girls,m[make_pair(ami,c)].girls);
        maxi_pizzas=max(maxi_pizzas,m[make_pair(ami,c)].pizzas);
        maxi_taxi=max(maxi_taxi,m[make_pair(ami,c)].taxi);
    }
    vector<pair<string,int> > taxi,pizzas,girls;
    cout<<"If you want to call a taxi, you should call: ";
    for(map<pair<string,int>,phonebook>::iterator it=m.begin();it!=m.end();it++)
        if(it->second.taxi==maxi_taxi)
           taxi.push_back(it->first);
    sort(taxi.begin(),taxi.end(),comp);
    for(int c=0;c<taxi.size();c++)
        cout<<taxi[c].first<<(c==taxi.size()-1?".":", ");
    cout<<endl;
    cout<<"If you want to order a pizza, you should call: ";
    for(map<pair<string,int>,phonebook>::iterator it=m.begin();it!=m.end();it++)
        if(it->second.pizzas==maxi_pizzas)
           pizzas.push_back(it->first);
      sort(pizzas.begin(),pizzas.end(),comp);
    for(int c=0;c<pizzas.size();c++)
        cout<<pizzas[c].first<<(c==pizzas.size()-1?".":", ");
    cout<<endl;
    cout<<"If you want to go to a cafe with a wonderful girl, you should call: ";
    for(map<pair<string,int>,phonebook>::iterator it=m.begin();it!=m.end();it++)
        if(it->second.girls==maxi_girls)
            girls.push_back(it->first);
      sort(girls.begin(),girls.end(),comp);
      for(int c=0;c<girls.size();c++)
        cout<<girls[c].first<<(c==girls.size()-1?".":", ");
}