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
map<char,int> m;
 
 
string conversion_binaire(int n)
{
    string s;
    while(n!=0)
    {
        s=s+(char)('0'+n%2);
        n/=2;
    }
    while(s.size()!=8)
        s=s+'0';
    return s;
}
 
int conv_2(string s)
{
    long long tot=0;
    for(int c=0;c<s.size();c++)
        tot=tot*2+s[c]-'0';
    return tot;
}
 
int conv2;
 
int main()
{
#ifdef LOCAL
    ifstream in("input.txt");
#endif
string s;
getline(cin,s);
for(int c=0;c<s.size();c++)
{
    int previous=0;
    if(c>0)
        previous=conv_2(conversion_binaire(s[c-1]));
    cout<<(previous-conv_2(conversion_binaire((s[c])))+256)%256<<endl;
}
}