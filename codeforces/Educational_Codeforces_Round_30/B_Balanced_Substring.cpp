#include <iostream>
#include <map>
using namespace std;
 
int main() {
    string s;
    int trash;
    cin>>trash;
    cin>>s;
    int act = 0;
    map<int,int> m;
    int maxi = 0;
    m[0]=-1;
    for(int c=0;c<s.size();c++) {
        act+=(s[c]=='0'?-1:1);
        if(m.find(act)==m.end()) {
            m[act] = c;
        } else {
            maxi = max(maxi, (c-m[act]));
        }
    }
    cout<<(maxi);
}