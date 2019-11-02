#include <iostream>
 
using namespace std;
 
int main() {
    int T;
    cin>>T;
 
    while(T--) {
            long long int dest, v, l, r;
            cin>>dest>>v>>l>>r;
 
            long long int res = dest / v;
 
            l = (l+v-1)/v;
            l*=v;
            r = r/v;
            r*=v;
            
 
            res -= max(0LL, (r-l)/v+1);
            cout<<res<<endl;
    }
}