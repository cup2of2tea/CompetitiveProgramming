#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    int N,M;
    cin>>N>>M;
    vector<vector<int> > listeAdjacence(N);
    vector<vector<bool> > friends(N,vector<bool>(N,false));
    for(int c=0;c<M;c++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        listeAdjacence[a].push_back(b);
        listeAdjacence[b].push_back(a);
        friends[a][b]=friends[b][a]=true;
    }
    long long res = 1000000000;
    for(int c=0;c<N;c++) {
        for(int c2=0;c2<listeAdjacence[c].size();c2++) {
            int n = listeAdjacence[c][c2];
            for(int c3=0;c3<listeAdjacence[n].size();c3++) {
                int n2 = listeAdjacence[n][c3];
                if(n2==c || !friends[n2][c]) continue;
                res = min(res,(long long)( listeAdjacence[c].size()-2+listeAdjacence[n].size()-2+listeAdjacence[n2].size()-2));
            }
        }
    }
    if(res == 1000000000) cout<<-1;
    else
    cout<<res;
}