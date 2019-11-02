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
    if(a==0)
        return b;
    if(b==0)
        return a;
    return pgcd(b,a%b);
}
 
 
 
 
 
 
int main()
{
#ifdef LOCAL
    ifstream in("input.txt");
#endif
    set<int> set1;
    string s;
    stringstream ss;
    cin>>s;
    int gauche=0;
    s=s+',';
    for(int c=0;c<s.size();c++)
    {
        if(s[c]==',')
        {
            int z;
            ss.clear();
            ss<<s.substr(gauche,c-gauche);
            ss>>z;
            set1.insert(z);
            gauche=c+1;
        }
    }
    vector<int> v;
    for(set<int>::iterator it=set1.begin();it!=set1.end();it++)
        v.push_back(*it);
    sort(v.begin(),v.end());
    int first=v[0];
    for(int c=1;c<v.size();c++)
    {
        if(v[c]==v[c-1]+1)
            continue;
        if(first<v[c-1])
            cout<<first<<"-"<<v[c-1]<<",";
        else if(first==v[c-1])
            cout<<first<<",";
        else
            cout<<first<<","<<v[c-1]<<",";
        first=v[c];
    }
    if(first<v[v.size()-1])
            cout<<first<<"-"<<v[v.size()-1];
    else
            cout<<first;
}