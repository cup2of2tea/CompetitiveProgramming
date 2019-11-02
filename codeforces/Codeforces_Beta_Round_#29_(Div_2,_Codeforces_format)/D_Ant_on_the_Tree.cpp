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
 
 
vector<int> chemin;
 
int bfs(int de,int to,int precedent,int mat[302][302],int n)
{
    if(de==to)
        return 1;
    for(int c=0;c<=n;c++)
    {
        if(c==precedent)
            continue;
        if(mat[to][c]==1)
        {
            if(bfs(de,c,to,mat,n))
            {
                chemin.push_back(to);
                return 1;
            }
        }
    }
    return 0;
}
 
 
int main()
{
#ifdef LOCAL
    ifstream in("input.txt");
#endif
    int mat[302][302];
    int n;
    cin>>n;
    for(int c=0;c<=301;c++)
        for(int c2=0;c2<=301;c2++)
            mat[c][c2]=0;
        for(int c=0;c<n-1;c++)
        {
            int a,b;
            cin>>a>>b;
            mat[a][b]=1;
            mat[b][a]=1;
        }
    int precedent=1;
    chemin.push_back(1);
    while(!cin.eof())
    {
         int x;
         cin>>x;
         bfs(precedent,x,0,mat,n);
        precedent=x;
     }
     bfs(precedent,1,0,mat,n);
     if(chemin.size()!=2*n-1)
    {
        cout<<-1;
        return 0;
    }
    for(int c=0;c<chemin.size();c++)
        cout<<chemin[c]<<" ";
 
}