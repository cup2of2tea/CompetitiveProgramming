#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
 
using namespace std;
 
long long compute(vector<vector<long long int> > &matrix, vector<int> &offsets){
    long long res = 0;
    vector<long long int> maxi(matrix.size(),0);
    for(int c=0;c<matrix.size();c++) {
        for(int c2=0;c2<matrix[c].size();c2++) {
 
 
            maxi[c] = max(maxi[c], matrix[(c+offsets[c2])%matrix.size()][c2]);
            /*if(offsets[0]==0&&offsets[1]==3&&offsets[2]==3){
                cout<<matrix[(c+offsets[c2])%matrix.size()][c2]<<endl;
                cout<<c<<" "<<c+offsets[c2]<<" "<<c2<<" "<<maxi[c]<<endl;
            }*/
 
        }
    }
    for(int c=0;c<maxi.size();c++) res += maxi[c];
    /*if(res == 3996) {
        for(int c2=0;c2<maxi.size();c2++) cout<<maxi[c2]<<" ";
        cout<<endl;
        for(int c2=0;c2<offsets.size();c2++) cout<<offsets[c2]<<" ";
        cout<<endl;
 
    }*/
    return res;
}
 
long long goCrazy(vector<vector<long long int> > &matrix, vector<int> &offsets, vector<int> &funnyCols, int i){
    long long res = compute(matrix, offsets);
    if(i >= funnyCols.size()) return res;
 
    for(int c=0;c<matrix.size();c++) {
        offsets[funnyCols[i]] = c;
        res = max(res, goCrazy(matrix, offsets, funnyCols, i+1));
    }
    return res;
}
 
int main() {
    ios_base::sync_with_stdio(false);
 
    int t;
    cin>>t;
    while(t--) {
        int n,m;
        cin>>n>>m;
        vector<vector<long long int> > matrix(n,vector<long long int>(m));
        priority_queue<pair<long long int,int> > q;
        for(int c=0;c<n;c++) {
            for(int c2=0;c2<m;c2++) {
                cin>>matrix[c][c2];
                //cout<<matrix[c][c2]<<" ";
                q.push(make_pair(matrix[c][c2],c2));
            }
 
            //cout<<endl;
        }
        int maxi = q.top().first;
 
 
        int cols = 0;
        for(int c=0;c<n;c++) {
            bool presence = false;
            for(int c2=0;c2<m;c2++) {
                if(matrix[c][c2] == maxi) {
                    presence = true;
                }
            }
            if(presence) cols++;
        }
 
        if(cols >= 4) {
            cout<<maxi*4<<endl;
            continue;
        }
 
        set<int> funnyCols;
        while(funnyCols.size() < 4 && q.size() > 0) {
            funnyCols.insert(q.top().second);
            q.pop();
        }
        vector<int> bla;
        vector<int> offsets(m,0);
        for(auto z:funnyCols) bla.push_back(z);
        cout<<goCrazy(matrix, offsets, bla, 0)<<endl;
    }
}