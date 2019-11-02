#include <bits/stdc++.h>
 
using namespace std;
 
 
 
int main(int argc, char **argv)
{
    map<pair<int,int>,bool> d;
 
 
    int n;
    cin>>n;
 
    vector<int> x(n);
    vector<int> y(n);
 
 
    for(int c=0;c<n;c++) {
        cin>>x[c]>>y[c];
    }
 
    vector<int> dxs(n);
    vector<int> dys(n);
 
    for(int c=0;c<n;c++) {
        int dx, dy;
        cin>>dx>>dy;
        dxs[c]=dx;
        dys[c]=dy;
        d[make_pair(dx,dy)]=true;
    }
 
    int xT,yT;
 
    for(int c=0;c<n;c++) {
        xT = x[0] + dxs[c];
        yT = y[0] + dys[c];
 
        for(int c2=1;c2<n;c2++) {
            if(d.find(make_pair(xT-x[c2],yT-y[c2]))==d.end()){
                goto nop;
            }
        }
        break;
        nop:;
    }
    cout<<xT<<" "<<yT;
}