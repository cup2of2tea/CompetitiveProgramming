#include <bits/stdc++.h>
using namespace std;
 
 
bool ok(int z) {
    if(z<10) return true;
    set<int> s;
    while(z) {
        if(s.find(z%10) != s.end()) return false;
        s.insert(z%10);
        z/=10;
    }
    return true;
}
 
int main() {
    int l,r;
    cin>>l>>r;
    for(int c = l; c <= r; c++) {
        if(ok(c)) {
            cout<<c;
            return 0;
        }
    }
    cout<<-1;
}