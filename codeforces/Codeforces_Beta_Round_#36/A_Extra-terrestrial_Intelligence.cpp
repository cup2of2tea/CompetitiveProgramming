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
#ifndef LOCAL
#define LOCAL
#endif
#ifdef LOCAL
#define cin in
#define cout out
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
    ofstream out("output.txt");
#endif
    int n;
    cin>>n;
    string s;
    cin>>s;
    int c=0;
    while(s[c]=='0')
        c++;
    int c2=c+1;
    while(s[c2]!='1')
        c2++;
    int ecart=c2-c;
    for(;c2<s.size();c2++)
    {
        if(s[c2]=='1')
        {
            int c3=c2+1;
            while(s[c3]!='1'&&c3<s.size())
                c3++;
            if(c3-c2!=ecart&&c3<s.size())
            {
                cout<<"NO";
                return 0;
            }
            c2=c3-1;
        }
    }
    cout<<"YES";
}