#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <map>
 
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
    if(a>b)
        swap(a,b);
    if(a==b||a==1)
        return a;
    return pgcd(a,b-a);
}
 
int main()
{
    #ifdef LOCAL
        ifstream in("input.txt");
    #endif
    int n,x0;
    cin>>n>>x0;
    int mini=0,maxi=10000000;
    for(int c=0;c<n;c++)
    {
        int a,b;
        cin>>a>>b;
        if(b<a)
            swap(a,b);
        mini=max(a,mini);
        maxi=min(b,maxi);
    }
    if(maxi<mini)
        cout<<-1;
    else if(x0<=maxi&&x0>=mini)
        cout<<0;
    else if(x0>maxi)
        cout<<x0-maxi;
    else
        cout<<mini-x0;
}