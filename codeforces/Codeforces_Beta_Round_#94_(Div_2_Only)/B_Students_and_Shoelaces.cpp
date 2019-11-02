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
#endif
    int n,m;
    cin>>n>>m;
    vector<vector<int> > liste_adjacence(n);
    int fir=0;
    vector<bool> fired(n);
    for(int c=0;c<n;c++) fired[c]=false;
    for(int c=0;c<m;c++)
    {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        liste_adjacence[a].push_back(b);
        liste_adjacence[b].push_back(a);
    }
    while(true)
    {
        vector<bool> fired2(n);
        for(int c=0;c<n;c++) fired2[c]=fired[c];
        bool aucun_changement=true;
        for(int c=0;c<n;c++)
        {
            if(fired[c])
                continue;
            int tot=0;
            for(int c2=0;c2<liste_adjacence[c].size()&&tot<=1;c2++)
            {
                if(!fired[liste_adjacence[c][c2]])
                    tot++;
            }
            if(tot==1)
            {
                aucun_changement=false;
                fired2[c]=true;
            }
        }
        if(aucun_changement)
            break;
        fir++;
        for(int c=0;c<n;c++) fired[c]=fired2[c];
    }
    cout<<fir;
}