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
#ifndef LOCAL
#define LOCAL
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
    int n,k;
    cin>>n>>k;
    vector<string> drawing(n);
    vector<string> model(n);
    for(int c=0;c<n;c++)
        cin>>drawing[c];
    if(k==1)
    {
        for(int c=0;c<drawing.size();c++)
            cout<<drawing[c]<<endl;
        return 0;
    }
    k--;
    for(int c=0;c<drawing.size();c++)
        model[c]=drawing[c];
    for(int c5=0;c5<k;c5++)
    {
        vector<string> new_drawing(drawing.size()*n);
        for(int c2=0;c2<new_drawing.size();c2++)
            new_drawing[c2].resize(new_drawing.size());
        for(int c=0;c<drawing.size();c++)
        {
            for(int c2=0;c2<drawing[c].size();c2++)
            {
                if(drawing[c][c2]=='*')
                {
                    for(int c3=0;c3<n;c3++)
                        for(int c4=0;c4<n;c4++)
                            new_drawing[c*n+c3][c2*n+c4]='*';
                }
                else
                {
                    for(int c3=0;c3<n;c3++)
                        for(int c4=0;c4<n;c4++)
                            new_drawing[c*n+c3][c2*n+c4]=model[c3][c4];
                }
            }
        }
        drawing=new_drawing;
    }
    for(int c=0;c<drawing.size();c++)
        cout<<drawing[c]<<endl;
 
}