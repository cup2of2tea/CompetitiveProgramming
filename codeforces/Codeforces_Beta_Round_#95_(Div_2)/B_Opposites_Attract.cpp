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
 
struct triplet
{
    int a;
    int b;
    int c;
};
 
 
int main()
{
#ifdef LOCAL
        ifstream in("input.txt");
        ofstream out("output.txt");
#endif
    long long int n;
    cin>>n;
    map<long long int,long long int> m;
    for(long long c=-10;c<=10;c++)
        m[c]=0;
    long long zero=0;
    for(long long c=0;c<n;c++){ long long z;cin>>z;m[z]++;if(z==0) zero++;}
    long long int total=0;
    for(int c=1;c<=10;c++){total+=m[c]*m[c*(-1)];}
    total+=(long long int)((zero*(zero-1)/2));
    cout<<(long long int)total;
}