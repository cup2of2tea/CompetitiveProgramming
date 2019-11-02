#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
 
 
 
int main() {
    int n,w,v,u;
    cin>>n>>w>>v>>u;
 
    vector<pair<int,int> > points(n);
    for(int c=0;c<n;c++) cin>>points[c].second>>points[c].first;
    sort(points.begin(),points.end());
 
    bool ok = true;
 
    double tAct = 0;
    int xAct = 0;
 
    for(int c=0;c<points.size();c++) {
        //cout<<(ok?"Yes ":"No ");
        //cout<<tAct<<" "<<xAct<<endl;
        double tToCome = static_cast<double>(points[c].second)/static_cast<double>(v);
        if(tToCome*static_cast<double>(u)<points[c].first){
            ok = false;
        }
        tAct = max(tToCome,tAct+static_cast<double>(points[c].first-xAct)/static_cast<double>(u));
        xAct = points[c].first;
    }
    //cout<<(ok?"Yes ":"No ");
    //cout<<tAct<<" "<<xAct<<endl;
    if(ok) {
        cout<<fixed<<setprecision(10)<<static_cast<double>(w)/static_cast<double>(u);
    } else {
        tAct += static_cast<double>(w-xAct)/static_cast<double>(u);
        cout<<fixed<<setprecision(10)<<tAct;
    }
}