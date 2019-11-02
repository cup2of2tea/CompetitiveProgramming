#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
 
int main()
{
    int n;
    cin>>n;
    int res = 0;
    vector<int> v (n);
    vector<vector<int> > matrice_adjacence(1001,vector<int>(1001,0));
    vector<bool> seuls(1001,true);
    for(int c=0;c<n;c++)
    {
        int a,b;
        cin>>a>>b;
        matrice_adjacence[a][b]++;
        if(a!=b) seuls[b]=false;
        v[c]=a;
    }
    vector<int> num(1001,0);
    for(int c=0;c<n;c++)
    {
        num[v[c]]++;
        res++;
        for(int c2=0;c2<n;c2++)
        {
            if(c==c2) continue;
            if(matrice_adjacence[v[c2]][v[c]])
            {
                res--;
                break;
            }
        }
    }
    vector<bool> vis(1001,false);
    for(int c=0;c<n;c++)
    {
        if(!vis[v[c]]&&matrice_adjacence[v[c]][v[c]]==1&&num[v[c]]>1&&seuls[v[c]])
        {
            vis[v[c]]=true;
            res++;
        }
    }
    cout<<res;
}