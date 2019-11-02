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
 
 
#define MOD 1000000007
 
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
 
void afficher_resultat(vector<vector<short> > &b,string X,int n,int m)
{
    if(n==0||m==0)
        return;
    if(b[n][m]==0)
    {
        afficher_resultat(b,X,n-1,m-1);
        cout<<X[n-1];
    }
    else if(b[n][m]==1)
        afficher_resultat(b,X,n-1,m);
    else
        afficher_resultat(b,X,n,m-1);
}
 
 
long long int recursif(int N,int K,int a,int b,int etat)
{
    if(K<0||a<1||b<1)
        return 0;
    else if(K==0&&a==1&&b==1)
        return 1;
    if(etat==0)
        return (recursif(N,K,a-1,b,1)+recursif(N,K,a,b-1,2))%MOD;
    if(etat==1)
        return (recursif(N,K-1,a,b-1,2)+recursif(N,K,a-1,b,1))%MOD;
    return (recursif(N,K-1,a-1,b,1)+recursif(N,K,a,b-1,2))%MOD;
}
 
//Warning: cout.precision(), division par 0, long long
 
int main()
{
#ifdef LOCAL
    ifstream in("input.txt");
#endif
    int n;
    cin>>n;
    map<long long,vector<long long> >liste_adjacence;
    for(int c=0;c<n;c++)
    {
        long long a,b;
        cin>>a>>b;
        liste_adjacence[a].push_back(b);
        liste_adjacence[b].push_back(a);
    }
    int precedent=-1;
    for(int c=0;c<n+1;c++)
    {
        if(c==n)
        {
            cout<<precedent;
            break;
        }
        if(precedent==-1)
        for(map<long long,vector<long long> >::iterator it=liste_adjacence.begin();it!=liste_adjacence.end();it++)
            if((*it).second.size()==1)
            {
                precedent=(*it).first;
                break;
            }
 
        cout<<precedent<<" ";
        int z=liste_adjacence[precedent].back();
        liste_adjacence[precedent].pop_back();
        for(int c2=0;c2<liste_adjacence[z].size();c2++)
            if(liste_adjacence[z][c2]==precedent)
            {
 
                liste_adjacence[z].erase(liste_adjacence[z].begin()+c2);
                break;
            }
        precedent=z;
    }
}