#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main()
{
    int N,M;
    cin>>N>>M;
    vector<vector<int> > v(M,vector<int>(N));
    for(int c=0;c<v.size();c++) for(int c2=0;c2<v[c].size();c2++) cin>>v[c][c2];
    vector<int> byCities(M,1);
    for(int c=0;c<v.size();c++) for(int c2=0;c2<v[c].size();c2++) if(v[c][c2] > v[c][byCities[c]-1]) byCities[c] = c2+1;
    sort(byCities.begin(),byCities.end());
    int act = 0;
    int idAct = -1;
    int winner = -1;
    int best = 0;
    for(int c=0;c<byCities.size();c++)
    {
        if(idAct == byCities[c]) act++;
        else {
            idAct = byCities[c];
            act=1;
        }
        if(best < act) {
            best = act;
            winner = idAct;
        }
    }
    cout<<winner;
}