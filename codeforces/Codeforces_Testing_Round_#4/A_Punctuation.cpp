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
 
#define LOCAL
#ifdef ONLINE_JUDGE
#undef LOCAL
#endif
 
#ifdef LOCAL
#define cin in
#define cout out
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
    string s;
    getline(cin,s);
    bool espace=true;
    string resultat="";
    for(int c=0;c<s.size();c++)
    {
        if(s[c]==' '&&espace) continue;
        if(s[c]==','||s[c]=='?'||s[c]=='!'||s[c]=='.')
        {
            resultat+=s[c];
            resultat+=' ';
            espace=true;
        }
        else if (s[c]==' ')
        {
            resultat+=' ';
            espace=true;
        }
        else
        {
            espace=false;
            resultat+=s[c];
        }
    }
    for(int c=0;c<resultat.size()-1;c++)
    {
            if(resultat[c]==' '&&(resultat[c+1]==','||resultat[c+1]=='?'||resultat[c+1]=='!'||resultat[c+1]=='.'))
            {
                resultat.erase(resultat.begin()+c);
                c--;
            }
    }
    cout<<resultat;
}