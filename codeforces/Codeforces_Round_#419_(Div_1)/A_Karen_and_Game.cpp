#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int> > v(n,vector<int>(m));
    for(int c=0;c<n;c++) for(int c2=0;c2<m;c2++) cin>>v[c][c2];
    int miniFirstLine = (*min_element(v[0].begin(),v[0].end()));
 
 
    vector<int> rowsBest(n);
    vector<int> colsBest(m);
    int best = 1e9;
 
    for(int c=0;c<=miniFirstLine;c++) {
        vector<int> rows(n,0);
        vector<int> cols(m,0);
        int act = c;
        rows[0]= c;
        vector<vector<int> > vcopy(v.size());
        for(int c2=0;c2<v.size();c2++) {
            vcopy[c2].resize(v[c2].size());
            copy(v[c2].begin(),v[c2].end(),vcopy[c2].begin());
        }
        for(int c2=0;c2<m;c2++){
            vcopy[0][c2]-=c;
            cols[c2] = vcopy[0][c2];
            act += cols[c2];
            for(int c3=1;c3<n;c3++) {
                vcopy[c3][c2] -= vcopy[0][c2];
            }
        }
 
        for(int c2=1;c2<n;c2++) {
            rows[c2] = vcopy[c2][0];
            if(rows[c2] < 0) {
                goto nop;
            }
            act += rows[c2];
            for(int c3=0;c3<m;c3++) {
                if(vcopy[c2][c3] != rows[c2]) {
                    goto nop;
                }
            }
        }
 
        if(act < best) {
            copy(rows.begin(),rows.end(),rowsBest.begin());
            copy(cols.begin(),cols.end(),colsBest.begin());
            best = act;
        }
 
        nop: ;
    }
 
    if(best > 1e8) {
        cout<<-1;
    } else {
        cout<<best<<endl;
        for(int c=0;c<rowsBest.size();c++) {
            for(int c2=0;c2<rowsBest[c];c2++) {
                cout<<"row "<<c+1<<endl;
            }
        }
        for(int c=0;c<colsBest.size();c++) {
            for(int c2=0;c2<colsBest[c];c2++) {
                cout<<"col "<<c+1<<endl;
            }
        }
    }
    return 0;
}