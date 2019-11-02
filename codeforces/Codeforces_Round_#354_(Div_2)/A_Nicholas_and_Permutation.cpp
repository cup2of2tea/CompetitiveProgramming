#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    int res = 0;
    for(int c=0;c<n;c++) cin>>v[c];
    int mini = (*min_element(v.begin(),v.end()));
    int maxi = (*max_element(v.begin(),v.end()));
    for(int c=0;c<n;c++) {
        for(int c2=0;c2<n;c2++) {
            if(c==c2) continue;
            swap(v[c],v[c2]);
            int one = -1, two = -1;
            for(int c3=0;c3<n;c3++) {
                if(v[c3] == mini) one = c3;
                if(v[c3] == maxi) two = c3;
            }
            res = max(res,abs(two-one));
            swap(v[c],v[c2]);
        }
    }
    cout<<res;
}