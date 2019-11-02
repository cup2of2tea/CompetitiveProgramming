#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
 
using namespace std;
 
 
 
int main() {
    int T;
    cin>>T;
    while(T--) {
        int N,M;
        cin>>N>>M;
        vector<string> v(N);
        for(int c=0;c<N;c++) cin>>v[c];
 
        vector<int> cols(M,0);
 
        for(int c=0;c<N;c++) {
            for(int c2=0;c2<M;c2++) {
                cols[c2] += v[c][c2] == '.';
            }
        }
 
        int mini = (*min_element(cols.begin(),cols.end()));
 
        //cout<<"min col "<<mini<<endl;
 
        vector<bool> bonus(M,false);
 
        for(int c=0;c<cols.size();c++) if(cols[c] == mini) bonus[c] = true;
 
        int res = 1e8+1;
 
        for(int c=0;c<N;c++) {
            int s = 0;
            int b = 0;
            for(int c2=0;c2<M;c2++) {
                if(v[c][c2] == '.'){
                    if(bonus[c2]) b = 1;
                    s++;
                }
            }
            s-=b;
            res = min(res, s);
        }
        cout<<res+mini<<endl;
    }
}