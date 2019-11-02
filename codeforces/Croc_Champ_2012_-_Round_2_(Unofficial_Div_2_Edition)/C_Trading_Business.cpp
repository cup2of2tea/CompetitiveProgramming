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
 
typedef struct machin
{
    machin(){}
    int buy;
    int sell;
    int nb;
};
 
int main()
{
#ifdef LOCAL
    ifstream in("input.txt");
#endif
    int nb_planetes,nb_types,capacite;
    cin>>nb_planetes>>nb_types>>capacite;
    vector<vector<machin> > v(nb_planetes,vector<machin>(nb_types));
    for(int c=0;c<nb_planetes;c++)
    {
        string osef;
        cin>>osef;
        for(int c2=0;c2<nb_types;c2++)
        {
            cin>>v[c][c2].buy>>v[c][c2].sell>>v[c][c2].nb;
        }
    }
    int maxi=-1;
    for(int c=0;c<nb_planetes;c++)
        for(int c2=0;c2<nb_planetes;c2++)
        {
            if(c==c2)continue;
            vector<pair<int,int> > differences(nb_types);
            for(int c3=0;c3<nb_types;c3++)
            {
                differences[c3]=make_pair(max(0,v[c2][c3].sell-v[c][c3].buy),v[c][c3].nb);
            }
            sort(differences.begin(),differences.end());
            int capacite2=capacite;
            int tot=0;
            int indice=nb_types-1;;
            while(capacite2>0&&indice>=0)
            {
                int z=min(capacite2,differences[indice].second);
                tot+=differences[indice].first*z;
                indice--;
                capacite2-=z;
            }
            maxi=max(tot,maxi);
        }
    cout<<maxi;
}