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
    int x;
    int y;
    int z;
};
 
tripl m_t(int a,int b,int c)
{
    tripl res;
    res.x=a;
    res.y=b;
    res.z=c;
    return res;
}
 
int main()
{
#ifdef LOCAL
    ifstream in("input.txt");
    ofstream out("output.txt");
#endif
   int a,b,c;
   cin>>a>>b>>c;
   vector<vector<string> > v(a);
   for(int c=0;c<a;c++) v[c].resize(b);
   for(int c=0;c<a;c++) for(int c2=0;c2<b;c2++) cin>>v[c][c2];
   vector<tripl> to_do;
   int x,y;
   cin>>x>>y;
   x--;
   y--;
   bool visites[10][10][10]={false};
   for(int c=0;c<10;c++) for(int c2=0;c2<10;c2++) for(int c3=0;c3<10;c3++) visites[c][c2][c3]=false;
   visites[x][y][0]=true;
   to_do.push_back(m_t(x,y,0));
   int tot=1;
   while(!to_do.empty())
   {
       x=to_do.back().x;
       y=to_do.back().y;
       int z=to_do.back().z;
       to_do.pop_back();
       int dx[6]={0,0,1,-1,0,0};
       int dy[6]={0,0,0,0,1,-1};
       int dz[6]={1,-1,0,0,0,0};
       for(int c=0;c<6;c++)
       {
           int x2=x+dx[c];
           int y2=y+dy[c];
           int z2=z+dz[c];
           if(z2>=0&&z2<v.size()&&x2>=0&&x2<v[z2].size()&&y2>=0&&y2<v[z2][x2].size()&&!visites[x2][y2][z2]&&v[z2][x2][y2]=='.')
           {
                to_do.push_back(m_t(x2,y2,z2));
                tot++;
                visites[x2][y2][z2]=true;
           }
       }
   }
    cout<<tot;
}