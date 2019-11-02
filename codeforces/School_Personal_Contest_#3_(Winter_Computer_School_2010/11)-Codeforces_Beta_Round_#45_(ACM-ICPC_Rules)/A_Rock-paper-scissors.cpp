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
 
bool bat(string s,string s2)
{
   return (s=="rock"&&s2=="scissors")||(s=="scissors"&&s2=="paper")||(s=="paper"&&s2=="rock");
}
 
int main()
{
#ifdef LOCAL
    ifstream in("input.txt");
#endif
    string s[3];
    cin>>s[0]>>s[1]>>s[2];
    for(int c=0;c<3;c++)
    {
        for(int c2=1;c2<3;c2++)
        {
            if(!bat(s[c],s[(c+c2)%3]))
            goto end;
        }
        if(c==0)
            cout<<"F";
        else if(c==1)
            cout<<"M";
        else
            cout<<"S";
        return 0;
        end:;
    }
    cout<<"?";
 
}