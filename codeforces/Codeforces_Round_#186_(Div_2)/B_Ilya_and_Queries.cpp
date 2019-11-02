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
 
 
 
 
 
struct Node
{
    int b;
    int gauche;
    int droite;
    Node(){}
};
 
string s;
Node arbre[100][100000];
int taille=0;
 
 
int requete(int gauche,int droite,int x,int y)
{
    if(arbre[x][y].gauche>=gauche&&arbre[x][y].droite<=droite)
    {
        return arbre[x][y].b;
    }
    else if(arbre[x][y].gauche>droite||arbre[x][y].droite<gauche)
        return 0;
    int res=requete(gauche,droite,x-1,y*2);
    if(arbre[x-1][y*2].droite!=s.size()-1)
    {
        res+=requete(gauche,droite,x-1,y*2+1);
        int l1=arbre[x-1][y*2].droite,l2=arbre[x-1][y*2+1].gauche;
        if(l1>=gauche&&l2<=droite)
            res+=(s[l1]==s[l2]?1:0);
    }
    return res;
}
 
 
int main(int argc,char **argv)
{
#ifdef LOCAL
    ifstream in("input.txt");
#endif
 
    int n;
    getline(cin,s);
    n=s.size();
    for(int c=0;c<n;c++)
    {
        arbre[0][c].gauche=c;
        arbre[0][c].droite=c;
        arbre[0][c].b=0;
    }
    taille++;
    while(n>1)
    {
        for(int c=0;c<(n+1)/2;c++)
        {
            arbre[taille][c].gauche=arbre[taille-1][c*2].gauche;
            arbre[taille][c].b=arbre[taille-1][c*2].b;
            arbre[taille][c].droite=arbre[taille-1][c*2].droite;
            if(arbre[taille-1][c*2].droite!=s.size()-1)
            {
                arbre[taille][c].droite=arbre[taille-1][c*2+1].droite;
                arbre[taille][c].b+=arbre[taille-1][c*2+1].b;
                if(s[arbre[taille-1][c*2].droite]==s[arbre[taille-1][c*2+1].gauche])
                    arbre[taille][c].b++;
            }
        }
        n=(n+1)/2;
        taille++;
    }
 
    taille--;
    int m;
    cin>>m;
    for(int c=0;c<m;c++)
    {
        int gauche,droite;
        cin>>gauche>>droite;
 
        gauche--;
        droite--;
 
        cout<<requete(gauche,droite,taille,0)<<endl;
    }
}