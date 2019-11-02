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
 
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> a(n),b(n);
    for(int c=0;c<n;c++) {
        cin>>a[c]>>b[c];
    }
 
    int best = 0;
 
    for(int c=-1;c<1000;c++) {
        int act = 0;
        for(int c2=0;c2<n;c2++) {
            if(c >= b[c2] && (c-b[c2])%a[c2] == 0) {
                s[c2] =(s[c2]=='1'?'0':'1');
            }
            if(s[c2]=='1') act++;
        }
        best = max(best, act);
    }
    cout<<best;
}