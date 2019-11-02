#include <bits/stdc++.h>
using namespace std;
 
 
 
int main() {
    int h,w;
    cin>>h>>w;
    vector<int> hs(h);
    vector<int> ws(w);
    for(int c=0;c<hs.size();c++) {
        cin>>hs[c];
    }
    for(int c=0;c<ws.size();c++) {
        cin>>ws[c];
    }
 
    vector<vector<int> > nop(h,vector<int>(w,0));
 
    for(int c=0;c<hs.size();c++) {
        int c2;
        for(c2=0;c2<hs[c];c2++) {
            nop[c][c2] = 1;
        }
        if(c2 < w) nop[c][c2]=2;
    }
 
 
 
    for(int c=0;c<ws.size();c++) {
        int c2;
        for(c2=0;c2<ws[c];c2++) {
            if(nop[c2][c] == 2) {
                cout<<0;
                return 0;
            }
            nop[c2][c]=1;
        }
        if(c2<h) {
            if(nop[c2][c]==1) {
                cout<<0;
                return 0;
            }
            nop[c2][c]=2;
        }
    }
 
 
 
    long long res = 1;
 
    for(int c=0;c<hs.size();c++) {
        for(int c2=0;c2<ws.size();c2++) {
            if(!nop[c][c2]) res*=2,res%=(long long)(1e9+7);
        }
    }
    cout<<res;
}