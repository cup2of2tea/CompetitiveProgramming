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
    if(a==0||b==0)
        return 0;
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
   int a,b,heap;
   cin>>a>>b>>heap;
 
    bool player_1=true;
   while(true)
   {
    if(heap==0){
        cout<<(player_1?"1":"0");return 0;}
       if(player_1)
       {
            int z=pgcd(heap,a);
            if(heap<z){
                cout<<"1";
                return 0;
            }
            heap-=z;
       }
       else
       {int z=pgcd(heap,b);
           if(heap<z)
        {
            cout<<"0";
            return 0;
        }
        heap-=z;
       }
       player_1=(!(player_1));
   }
}