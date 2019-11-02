#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
    string res;
    cin>>res;
    int n;
    cin>>n;
    vector<string>v(n);
    bool one = false, two = false;
    bool ok = false;
    for(int c=0;c<n;c++) cin>>v[c];
    for(int c=0;c<v.size();c++) {
        if(v[c] == res) ok = true;
        if(v[c][0] == res[1]) one = true;
        if(v[c][1] == res[0]) two = true;
    }
    cout<<(ok || (one && two)?"YES":"NO");
}