#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
 
using namespace std;
 
 
 
int main() {
    int T;
    cin>>T;
    while(T--) {
        string s,t,p;
        cin>>s>>t>>p;
 
        vector<int> compte(26,0);
        for(int c=0;c<p.size();c++) compte[p[c]-'a']++;
 
        int i = 0;
        bool ok = true;
 
        for(int c=0;c<t.size();c++) {
            if(t[c] == s[i]){i++; continue;}
            if(compte[t[c]-'a'] >= 1) {
                compte[t[c]-'a']--;
            } else {
                ok = false;
            }
        }
        if(i != s.size()) ok = false;
        cout<<(ok?"YES":"NO")<<endl;
    }
}