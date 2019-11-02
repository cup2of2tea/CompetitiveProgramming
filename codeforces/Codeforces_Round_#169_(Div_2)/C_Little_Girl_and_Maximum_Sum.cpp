#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <istream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <list>
#include <cstdio>
#include <set>
#include <iomanip>
#include <stack>
#include <ctime>
#include <climits>
#include <iterator>
#define LOCAL
#ifdef ONLINE_JUDGE
#define COUT(s)
#undef LOCAL
#endif
#ifdef LOCAL
#define cin in
#define COUT(s) cout<<"-----"<<s<<"-----"<<endl;
#endif
using namespace std;
 
 
 
struct node
{
    node(){valeur=0;}
    int gauche;
    int droite;
    int valeur;
};
 
 
vector<int> puissance;
void update(int g,int d,vector<vector<node> > &tree,int x,int y)
{
    if(x<0) return;
    if(y>=tree[x].size())
        return;
    if(tree[x][y].gauche>=g&&tree[x][y].droite<=d)
    {
        tree[x][y].valeur++;
    }
    else if(tree[x][y].gauche<=g||tree[x][y].droite>=d)
    {
        update(g,d,tree,x-1,y*2+1);
        update(g,d,tree,x-1,y*2);
    }
}
 
void get_puissance(vector<vector<node> > &tree,int x,int y)
{
    if(x<0) return;
    if(y>=tree[x].size())
        return;
    for(int c=tree[x][y].gauche;c<=tree[x][y].droite;c++)
        puissance[c]+=tree[x][y].valeur;
    get_puissance(tree,x-1,y*2);
    get_puissance(tree,x-1,y*2+1);
}
 
int main(int argc,char **argv)
{
#ifdef LOCAL
    ifstream in("input.txt");
    ofstream out("output.txt");
#endif
    int n,q;
    scanf(" %d %d",&n,&q);
    vector<int> valeur(n);
    for(int c=0;c<n;c++)
    {
        scanf(" %d",&valeur[c]);
    }
    sort(valeur.begin(),valeur.end());
    vector<int> res(n+1,0);
    for(int c=0;c<q;c++)
    {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        res[a]++;
        res[b+1]--;
    }
    for(int c=1;c<n;c++)
    {
        res[c]=res[c]+res[c-1];
    }
    sort(res.begin(),res.end());
    long long sum=0;
    for(int c=1;c<res.size();c++)
    {
        sum=sum+static_cast<long long>(valeur[c-1])*static_cast<long long>(res[c]);}
    printf("%I64d",sum);
}