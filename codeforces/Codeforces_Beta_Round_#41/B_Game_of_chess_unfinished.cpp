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
#include <ctime>
#define LOCAL
#ifdef ONLINE_JUDGE
#undef LOCAL
#endif
 
#ifdef LOCAL
#define cin in
#endif
#define FOREACH(i, n) for (typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
#define MEMSET(p, c) memset(p, c, sizeof(p))
 
using namespace std;
 
template < typename  T,typename  T2 >
T2 fac(T n)
{
    return n<2?1:fac<T,T2>(n-1)*n;
}
 
template < typename  T,typename  T2,typename  T3>
T2 fac(T n, T3 mod)
{
    return n<2?1:(fac<T,T2,T3>(n-1,mod)*n)%mod;
}
template <typename  T>
T nb_combinaisons(T k,T n)
{
    if(n<k)
        return nb_combinaisons<T>(n,k);
    return fac<T,long long int>(n)/(fac<T,long long int>(n-k)*fac<T,long long int>(k));
}
 
template <typename T,typename  T2>
T nb_permutations(vector<T2> v)
{
    T total=fac<T,T>(v.size());
    map<T2,T> m;
    bool distinct=true;
    for(long long unsigned c=0;c<v.size();c++)
    {
        m[v[c]]++;
        if(m[v[c]]-1)
            distinct=false;
    }
    for(typename map<T2,T>::iterator it=m.begin();it!=m.end();it++)
        total/=fac<T,T>(it->second);
    return total;
}
 
template <typename  T,typename  T2,typename  T3>
T nb_permutations(vector<T2> v,T3 mod)
{
    T total=fac<T,T,T3>(v.size(),mod);
    map<T2,T> m;
    bool distinct=true;
    for(long long unsigned c=0;c<v.size();c++)
    {
        m[v[c]]++;
        if(m[v[c]]-1)
            distinct=false;
    }
    for(typename map<T2,T>::iterator it=m.begin();it!=m.end();it++)
        total/=fac<T,T>(it->second);
    return total%mod;
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
 
string conversion(int n,int base)
{
    string res="";
    while(n!=0)
    {
        res=((char)('0'+n%base))+res;
        n/=base;
    }
    return res;
}
 
bool check(char chess[8][8])
{
    for(int c=0;c<8;c++)
        for(int c2=0;c2<8;c2++)
            if(chess[c][c2]=='T')
            {
                for(int c3=c-1;c3>=0;c3--)
                {
                    if(chess[c3][c2]=='.')
                        continue;
                    else if(chess[c3][c2]=='k')
                        return false;
                    else
                        break;
                }
                for(int c3=c+1;c3<8;c3++)
                {
                    if(chess[c3][c2]=='.')
                        continue;
                    else if(chess[c3][c2]=='k')
                        return false;
                    else
                        break;
                }
                for(int c3=c2-1;c3>=0;c3--)
                {
                    if(chess[c][c3]=='.')
                        continue;
                    else if(chess[c][c3]=='k')
                        return false;
                    else
                        break;
                }
                for(int c3=c2+1;c3<8;c3++)
                {
                    if(chess[c][c3]=='.')
                        continue;
                    else if(chess[c][c3]=='k')
                        return false;
                    else
                        break;
                }
            }
            else if(chess[c][c2]=='K')
            {
                int dx[8]={-1,-1,-1,0,0,1,1,1};
                int dy[8]={-1,0,1,-1,1,-1,0,1};
                for(int c3=0;c3<8;c3++)
                {
                    int x2=c+dx[c3];
                    int y2=c2+dy[c3];
                    if(x2>=0&&x2<8&&y2>=0&&y2<8&&chess[x2][y2]=='k')
                        return false;
                }
            }
    return true;
}
 
int main()
{
#ifdef LOCAL
    ifstream in("input.txt");
#endif
    string s[4];
    for(int c=0;c<4;c++)
        cin>>s[c];
    char chess[8][8];
    for(int c=0;c<8;c++) for(int c2=0;c2<8;c2++) chess[c][c2]='.';
    for(int c=0;c<4;c++)
        chess[s[c][0]-'a'][s[c][1]-'0'-1]=(c<2?'T':(c==2?'K':'k'));
    int dx[8]={-1,-1,-1,0,0,1,1,1};
    int dy[8]={-1,0,1,-1,1,-1,0,1};
    if(check(chess))
    {
        cout<<"OTHER";
        return 0;
    }
    int x=s[3][0]-'a',y=s[3][1]-'0'-1;
    for(int c=0;c<8;c++)
    {
        int x2=x+dx[c];
        int y2=y+dy[c];
        if(x2>=0&&x2<8&&y2>=0&&y2<8)
        {
            char temp=chess[x2][y2];
            chess[x2][y2]='k';
            chess[x][y]='.';
            if(check(chess))
            {
                cout<<"OTHER";
                return 0;
            }
            chess[x2][y2]=temp;
            chess[x][y]='k';
        }
    }
    cout<<"CHECKMATE";
}