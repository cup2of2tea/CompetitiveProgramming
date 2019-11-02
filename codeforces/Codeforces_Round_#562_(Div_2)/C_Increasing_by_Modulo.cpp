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
    vector<int> v(n);
    for(int c=0;c<n;c++) cin>>v[c];
 
    int gauche = 0, droite = m;
    while(gauche != droite) {
        int mid = (gauche + droite) / 2;
 
 
        int previous = 1e8;
 
        bool ok = true;
        for(int c=n-1;c>=0;c--) {
            if(mid + v[c] >= previous && v[c] <= previous){
                continue;
            } else {
                if(v[c] > previous) {
                    if(v[c]+mid <m){
                        ok = false;
                        break;
                    } else {
                        previous = min(previous, (v[c]+mid)%m);
                    }
                } else {
                    previous = v[c]+mid;
                }
            }
        }
        if(!ok) {
            gauche = mid + 1;
        } else {
            droite = mid;
        }
    }
    cout<<gauche<<endl;
    return 0;
}