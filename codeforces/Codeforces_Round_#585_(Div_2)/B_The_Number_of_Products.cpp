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
    long long int n;
    cin>>n;
    vector<long long int> v(n);
    for(int c=0;c<n;c++) {
        cin>>v[c];
    }
    long long int counts[2] = {0,0};
    long long int sums[2] = {0,0};
    long long int lastNeg = -1;
    int toogle = 0;
    long long int res = 0;
    for(int c=0;c<n;c++) {
        if(v[c] < 0) {
            sums[toogle] += (c-lastNeg);
            counts[toogle]++;
 
            lastNeg = c;
            toogle = (toogle+1)%2;
        }
        if(toogle == 0) {
            res += sums[(toogle)%2] + c - lastNeg;
        } else {
            res += sums[(toogle)%2] + c - lastNeg;
        }
    }
    cout<<(n*(n+1))/2-res<<" "<<res<<endl;
}