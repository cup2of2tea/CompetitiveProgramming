#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>
 
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
 
 
int main()
{
    #ifdef LOCAL
        ifstream in("input.txt");
    #endif
    int N,P1,P2,P3,T1,T2;
    cin>>N>>P1>>P2>>P3>>T1>>T2;
    int a,b;
    int total=0;
    int precedent=-1;
    for(int c=0;c<N;c++)
    {
        cin>>a>>b;
        if(precedent!=-1)
            if(precedent+T1<=a)
                if(precedent+T2+T1<=a)
                    total+=P1*T1+P2*T2+(a-precedent-T2-T1)*P3+(b-a)*P1;
                else
                    total+=P1*T1+(a-precedent-T1)*P2+(b-a)*P1;
            else
                total+=P1*(b-precedent);
        else
            total+=P1*(b-a);
        precedent=b;
    }
    cout<<total;
}
 