#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
 
using namespace std;
 
 
int main() {
    ios_base::sync_with_stdio(false);
 
    int N;
    cin>>N;
    vector<int> v(N);
    for(int c=0;c<N;c++) cin>>v[c];
    sort(v.begin(),v.end());
    vector<bool> done(N,false);
    int res = 0;
    for(int c=0;c<v.size();c++) {
        if(done[c]) continue;
        res++;
        for(int c2=c+1;c2<v.size();c2++) {
            if(v[c2]%v[c]==0) done[c2]=true;
        }
    }
    cout<<res;
}