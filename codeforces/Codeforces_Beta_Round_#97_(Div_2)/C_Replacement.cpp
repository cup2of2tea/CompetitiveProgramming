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
 
 
string conversion_ternaire(int a)
{
    string resultat="";
    while(a!=0)
    {
        resultat=(char)(a%3+'0')+resultat;
        a/=3;
    }
    return resultat;
}
 
int conversion_inverse(string s)
{
    int total=0;
    for(int c=0;c<s.size();c++)
    {
        total=total*3+s[c]-'0';
    }
    return total;
}
 
//Warning: cout.precision(), division par 0, long long
 
int main()
{
#ifdef LOCAL
    ifstream in("input.txt");
#endif
    int n;
    cin>>n;
    vector<long long int> v(n);
    for(int c=0;c<n;c++)
        cin>>v[c];
    sort(v.begin(),v.end());
    if(v.back()==1)
    {
        for(int c=0;c<v.size()-1;c++)
            cout<<1<<" ";
        cout<<2;
        return 0;
    }
    for(int c=v.size()-1;c>0;c--)
    {
        v[c]=v[c-1];
    }
    v[0]=1;
    for(int c=0;c<v.size();c++)
        cout<<v[c]<<" ";
}