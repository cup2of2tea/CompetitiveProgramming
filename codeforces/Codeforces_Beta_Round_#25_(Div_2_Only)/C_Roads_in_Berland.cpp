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
 
struct triplet
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
    int nb_cities;
    cin>>nb_cities;
    vector<vector<int> > graphe(nb_cities);
    for(int c=0;c<graphe.size();c++) graphe[c].resize(graphe.size());
    for(int c=0;c<graphe.size();c++)
        for(int c2=0;c2<graphe[c].size();c2++)
            cin>>graphe[c][c2];
    int k;
    cin>>k;
    for(int c=0;c<k;c++)
    {
        int a,b,longueur;
        cin>>a>>b>>longueur;
        a--;
        b--;
        graphe[a][b]=min(graphe[a][b],longueur);
        graphe[b][a]=min(graphe[b][a],longueur);
        for(int c2=0;c2<nb_cities;c2++)
            for(int c3=0;c3<nb_cities;c3++)
                graphe[c2][c3]=min(graphe[c2][c3],min(graphe[a][b]+graphe[b][c3]+graphe[c2][a],graphe[a][b]+graphe[b][c2]+graphe[c3][a]));
        long long int total=0;
        for(int c2=0;c2<nb_cities;c2++)
            for(int c3=0;c3<nb_cities;c3++)
                total+=graphe[c2][c3];
        cout<<total/2<<" ";
    }
}