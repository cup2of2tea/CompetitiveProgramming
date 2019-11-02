#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>
#include <set>
#include <chrono>
 
using namespace std;
 
 
int main() {
 
    int n,m;
    cin>>n>>m;
 
    vector<pair<int,int> > v(m);
    for(int c=0;c<v.size();c++) {
 
        cin>>v[c].first>>v[c].second;
        if(v[c].first > v[c].second) swap(v[c].first,v[c].second);
 
    }
 
    int sub1 = -1, sub2 = -1;
 
    bool ok = true;
 
    for(int c=0;c<v.size();c++) {
        if(v[c].first == v[0].first || v[c].second == v[0].first) continue;
        if(sub1 != -1) {
            if(sub1 != v[c].first && sub1 != v[c].second && sub2 != v[c].first && sub2 != v[c].second) {
                ok = false;
                break;
            }
            if(sub1 != v[c].first && sub1 != v[c].second){
                sub1 = -2;
            }
            if(sub2 != v[c].first && sub2 != v[c].second) {
                sub2 = -2;
            }
        } else {
 
            sub1 = v[c].first;
            sub2 = v[c].second;
        }
 
    }
 
 
    if(ok) {
        cout<<"YES";
        return 0;
    }
 
    ok = true;
    sub1 = -1;
    sub2 = -1;
 
    for(int c=0;c<v.size();c++) {
        if(v[c].first == v[0].second || v[c].second == v[0].second) continue;
        if(sub1 != -1) {
            if(sub1 != v[c].first && sub1 != v[c].second && sub2 != v[c].first && sub2 != v[c].second) {
                ok = false;
                break;
            }
            if(sub1 != v[c].first && sub1 != v[c].second){
                sub1 = -2;
            }
            if(sub2 != v[c].first && sub2 != v[c].second) {
                sub2 = -2;
            }
        }
        else {
                sub1 = v[c].first;
        sub2 = v[c].second;
 
        }
}
 
     if(ok) {
 
        cout<<"YES";
        return 0;
    }
    cout<<"NO";
    return 0;
}