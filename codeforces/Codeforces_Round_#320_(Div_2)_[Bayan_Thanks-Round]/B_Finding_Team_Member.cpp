#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    long long int n;
    cin>>n;
    vector<vector<pair<int,int> > > strenghts(2*n,vector<pair<int,int> >(2*n));
    for(int c=1;c<2*n;c++){
        for(int c2=0;c2<c;c2++){
            cin>>strenghts[c][c2].first;
            strenghts[c][c2].second = c2;
            strenghts[c2][c] = make_pair(strenghts[c][c2].first,c);
        }
    }
    for(int c=0;c<strenghts.size();c++) {
        sort(strenghts[c].begin(),strenghts[c].end());
    }
    vector<int> team(2*n);
    vector<bool> visites(2*n,false);
    for(int c=0;c<n;c++) {
        for(int c2=0;c2<strenghts.size();c2++){
            if(visites[c2]) continue;
            while(visites[strenghts[c2].back().second]) strenghts[c2].pop_back();
            int partenaire = strenghts[c2].back().second;
            while(visites[strenghts[partenaire].back().second]) strenghts[partenaire].pop_back();
            if(strenghts[partenaire].back().second == c2) {
                visites[c2] = visites[partenaire] = true;
                team[c2] = partenaire;
                team[partenaire] = c2;
                break;
            }
        }
    }
    for(int c=0;c<team.size();c++) cout<<team[c]+1<<" ";
}