#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin>>N;
    vector<int> v(N);
    for(int c=0;c<N;c++) cin>>v[c];
 
    int res = 1;
 
    map<int,bool> m;
    m[0] = true;
 
    for(int c=0;c<N;c++) {
        if(m[v[c]]) {
            m[v[c]]=false;
        } else {
            res++;
        }
        m[c+1]=true;
    }
    cout<<res;
}