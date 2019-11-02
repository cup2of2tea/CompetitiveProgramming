#include <bits/stdc++.h>
using namespace std;
 
long long  memo[200][200][2];
 
long long go(vector<int> &v,int i,int canCut,int nbCuts) {
    if(nbCuts == 0) return 1;
    if(v[i] == 1)
    {
        return go(v,i+1,1,nbCuts-canCut);
    }
    if(memo[i][nbCuts][canCut] != -1) return memo[i][nbCuts][canCut];
    memo[i][nbCuts][canCut] = 0;
    if(canCut)
    {
        memo[i][nbCuts][canCut]+=go(v,i+1,0,nbCuts-1);
    }
    memo[i][nbCuts][canCut]+=go(v,i+1,canCut,nbCuts);
    return memo[i][nbCuts][canCut];
}
 
 
int main()
{
    int n;
    cin>>n;
    for(int c=0;c<200;c++)for(int c2=0;c2<200;c2++) memo[c][c2][0] = memo[c][c2][1] = -1;
    int allCuts = 0;
    vector<int> v(n);
    for(int c=0;c<n;c++) {
        cin>>v[c];
        if(v[c]==1) allCuts++;
    }
    allCuts--;
    cout<<go(v,0,0,allCuts);
}