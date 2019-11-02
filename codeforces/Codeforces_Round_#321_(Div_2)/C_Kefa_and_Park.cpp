#include <bits/stdc++.h>
using namespace std;
 
int m;
 
int dfs(int prec, int act, int found, vector<vector<int> > &listeAdjacence, vector<bool> &cats)
{
    if(cats[act]) found++;
    else found = 0;
    if(found > m) return 0;
    if(listeAdjacence[act].size() == 1 && prec != -1) {
        return 1;
    }
    int res = 0;
    for(int c=0;c<listeAdjacence[act].size();c++) {
        int newNode = listeAdjacence[act][c];
        if(prec == newNode) continue;
        res += dfs(act, newNode, found, listeAdjacence, cats);
    }
    return res;
}
 
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n>>m;
    vector<bool> cats(n);
    for(int c=0;c<n;c++) {
        int z;
        cin>>z;
        cats[c] = (z?true:false);
    }
    vector<vector<int> > listeAdjacence(n);
    for(int c=0;c<n-1;c++) {
        int from,to;
        cin>>from>>to;
        from--;
        to--;
        listeAdjacence[from].push_back(to);
        listeAdjacence[to].push_back(from);
    }
    cout<<dfs(-1,0,0,listeAdjacence,cats);
}