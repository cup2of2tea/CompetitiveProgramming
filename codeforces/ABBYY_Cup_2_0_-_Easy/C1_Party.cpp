#include <iostream>
#include <map>
#include <vector>
#include <fstream>
using namespace std;
bool dislike[2000];
bool visites[2000];
bool visites2[2000];
short mat[2000][2000];
int n;
 
 
void go(int zone)
{
    visites2[zone]=visites[zone]=true;
    for(int c=0;c<n;c++)
        if(mat[zone][c]==-1)
            dislike[c]=true;
    for(int c=0;c<n;c++)
        if(mat[zone][c]==1&&!visites2[c])
            go(c);
}
 
int bfs(int zone)
{
    for(int c=0;c<n;c++)
        dislike[c]=false;
    for(int c=0;c<n;c++)
        visites2[c]=false;
    go(zone);
    int tot=0;
    for(int c=0;c<n;c++)
        if(visites2[c])
            if(dislike[c])
                return 0;
            else
                tot++;
    return tot;
}
 
int main()
{
    for(int c=0;c<2000;c++)
        for(int c2=0;c2<2000;c2++)
            mat[c][c2]=0;
    int m;
    cin>>n>>m;
    for(int c=0;c<m;c++)
    {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        mat[a][b]=mat[b][a]=1;
    }
    cin>>m;
    for(int c=0;c<m;c++)
    {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        mat[a][b]=mat[b][a]=-1;
    }
    for(int c=0;c<2000;c++)
        visites[c]=false;
    int maxi=-1;
    for(int c=0;c<n;c++)
        if(!visites[c])
            maxi=max(bfs(c),maxi);
    cout<<maxi;
}