#include <iostream>
#include <map>
#include <vector>
using namespace std;
 
int main() {
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int> > v(n,vector<int>(m));
 
    for(int c=0;c<n;c++) for(int c2=0;c2<m;c2++) cin>>v[c][c2];
 
    vector<vector<int> > partial(n,vector<int>(m,0));
    for(int c=0;c<n;c++) for(int c2=0;c2<m;c2++) {
        partial[c][c2] = v[c][c2];
        if(c>0) partial[c][c2]+=partial[c-1][c2];
    }
 
    long long tot = 0;
    long long removed = 0;
    for(int c=0;c<m;c++) {
        int bestScore = 0;
        int bestRemoved = 0;
        int actRemoved = 0;
 
        for(int c2=0;c2<n;c2++) {
            int s = partial[min(n-1,c2+k-1)][c];
            if(c2>0) s-=partial[c2-1][c];
            if(s > bestScore) {
                bestScore = s;
                bestRemoved = actRemoved;
            }
            if(v[c2][c] == 1) {
                actRemoved++;
            }
        }
        tot+=bestScore;
        removed += bestRemoved;
    }
 
    cout<<tot<<" "<<removed;
}