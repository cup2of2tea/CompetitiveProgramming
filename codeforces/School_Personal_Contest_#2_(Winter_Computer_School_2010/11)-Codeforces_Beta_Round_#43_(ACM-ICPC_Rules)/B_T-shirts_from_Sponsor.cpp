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
    ofstream out("output.txt");
#endif
   map<string,int> m;
   int a,b,c,d,e;
   cin>>a>>b>>c>>d>>e;
   m["S"]=a;
   m["M"]=b;
   m["L"]=c;
   m["XL"]=d;
   m["XXL"]=e;
   string truc[5]={"S","M","L","XL","XXL"};
   int n;
   cin>>n;
   for(int c=0;c<n;c++)
   {
       string s;
       cin>>s;
       if(m[s]>0)
       {
           m[s]--;
           cout<<s<<endl;
           continue;
       }
       int c2;
       for(c2=0;c2<5;c2++) if(truc[c2]==s) break;
       for(int c3=1;c3<=4;c3++)
       {
           if(c2+c3<5&&m[truc[c2+c3]]>0)
            {
                cout<<truc[c2+c3];
                m[truc[c2+c3]]--;
                break;
            }
            if(c2-c3>=0&&m[truc[c2-c3]]>0)
            {
                cout<<truc[c2-c3];
                m[truc[c2-c3]]--;
                break;
            }
       }
       cout<<endl;
   }
}