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
 
struct tripl
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
    int n;
    cin>>n;
    vector<tripl > road(n);
    for(int c=0;c<n;c++)
        cin>>road[c].a>>road[c].b>>road[c].c;
    int c1=0,c2=0;
    int p=1;
    int pr=0;
    for(int i=0;i<n;i++)
    {
        for(int r=0;r<n;r++)
        {
            if(r!=pr)
            {
                if(road[r].a==p)
                {
                    p=road[r].b;
                    c1+=road[r].c;
                    pr=r;
                    break;
                }
                if(road[r].b==p)
                {
                    p=road[r].a;
                    c2+=road[r].c;
                    pr=r;
                    break;
                }
            }
        }
    }
    cout<<min(c1,c2);
}