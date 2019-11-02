#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
 
int main() {
    int n,m;
    cin>>n>>m;
    vector<int> v(n);
    for(int c=0;c<n;c++) cin>>v[c];
    vector<int> v2(m);
    for(int c=0;c<m;c++) cin>>v2[c];
    sort(v2.rbegin(),v2.rend());
    
    int c2;
    for(int c=0;c<m;c++){
        for(c2=0;c2<n;c2++) {
            if(v[c2] == 0) {
                v[c2] = v2[c];
                break;
            }
        }
    }
    
 
    for(int c=0;c+1<n;c++) {
        if(v[c] > v[c+1]) {
            cout<<"Yes";
            return 0;
        }
    }
    cout<<"No"<<endl;
}