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
 
 
inline float dist(int x1, int y1, int x2, int y2)
{
        return sqrt(double(x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
bool aprox(float a, float b)
{
        if(abs(a - b) <= 0.01f)
                return 1;
        return 0;
}
 
 
 
bool voyelle(char car)
{
    return car=='a'||car=='e'||car=='i'||car=='o'||car=='u'||car=='y';
}
 
int main()
{
#ifdef LOCAL
    ifstream in("input.txt");
#endif
    int n,k;
    cin>>n>>k;
    bool aabb=true;
    bool abab=true;
    bool abba=true;
    for(int c=0;c<n;c++)
    {
        int c2;
        string tab[4];
        for(c2=0;c2<4;c2++)
            cin>>tab[c2];
        if(aabb)
        {
            int k2=0;
            bool win=true;
            for(c2=0;c2<min(tab[0].size(),tab[1].size())&&k2<k&&win;c2++)
            {
                if(tab[0][tab[0].size()-c2-1]!=tab[1][tab[1].size()-c2-1])
                    win=false;
                else if(voyelle(tab[0][tab[0].size()-c2-1]))
                    k2++;
            }
             if(k2<k)
                win=false;
            k2=0;
            for(c2=0;c2<min(tab[2].size(),tab[3].size())&&k2<k&&win;c2++)
            {
                if(tab[3][tab[3].size()-c2-1]!=tab[2][tab[2].size()-c2-1])
                    win=false;
                else if(voyelle(tab[2][tab[2].size()-c2-1]))
                    k2++;
            }
             if(k2<k)
                win=false;
            if(!win)
                aabb=false;
        }
        if(abab)
        {
            int k2=0;
            bool win=true;
            for(c2=0;c2<min(tab[0].size(),tab[2].size())&&k2<k&&win;c2++)
            {
                if(tab[0][tab[0].size()-c2-1]!=tab[2][tab[2].size()-c2-1])
                    win=false;
                else if(voyelle(tab[0][tab[0].size()-c2-1]))
                    k2++;
            }
             if(k2<k)
                win=false;
            k2=0;
            for(c2=0;c2<min(tab[1].size(),tab[3].size())&&k2<k&&win;c2++)
            {
                if(tab[3][tab[3].size()-c2-1]!=tab[1][tab[1].size()-c2-1])
                    win=false;
                else if(voyelle(tab[1][tab[1].size()-c2-1]))
                    k2++;
            }
             if(k2<k)
                win=false;
            if(!win)
                abab=false;
        }
        if(abba)
        {
            int k2=0;
            bool win=true;
            for(c2=0;c2<min(tab[0].size(),tab[3].size())&&k2<k&&win;c2++)
            {
                if(tab[0][tab[0].size()-c2-1]!=tab[3][tab[3].size()-c2-1])
                    win=false;
                else if(voyelle(tab[0][tab[0].size()-c2-1]))
                    k2++;
            }
             if(k2<k)
                win=false;
            k2=0;
            for(c2=0;c2<min(tab[1].size(),tab[2].size())&&k2<k&&win;c2++)
            {
                if(tab[2][tab[2].size()-c2-1]!=tab[1][tab[1].size()-c2-1])
                    win=false;
                else if(voyelle(tab[1][tab[1].size()-c2-1]))
                    k2++;
            }
            if(k2<k)
                win=false;
            if(!win)
                abba=false;
        }
    }
    if(abab)
    {
        if(abba)
        {
            cout<<"aaaa";
            return 0;
        }
        cout<<"abab";
    }
    else if(abba)
    {
        cout<<"abba";
    }
    else if(aabb)
    {
        cout<<"aabb";
    }
    else
        cout<<"NO";
}