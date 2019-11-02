#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <map>
#include <cstdio>
 
 
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
    int a1,a2,b1,b2,c1,c2;
    cin>>a1>>b1>>c1>>a2>>b2>>c2;
 
    // null set
    if(a1==0 && b1==0 && c1!=0){    cout<<0;    return 0;   }
    if(a2==0 && b2==0 && c2!=0){    cout<<0;    return 0;   }
 
    // universal set
//  if(a1==0 && b1==0 && c1==0){    cout<<-1;   return 0;   }
//  if(a2==0 && b2==0 && c2==0){    cout<<-1;   return 0;   }
 
    // line
    if(a1*b2-a2*b1!=0)  cout<<1;    // intersect
    else if(a1*c2-a2*c1==0 && b1*c2-b2*c1==0)   cout<<-1;   // parallel
    else    cout<<0;
 
    return 0;
}