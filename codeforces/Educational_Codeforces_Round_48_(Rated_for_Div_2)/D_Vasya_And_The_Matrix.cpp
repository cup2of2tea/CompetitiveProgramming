#include <bits/stdc++.h>
 
 
using namespace std;
 
 
vector<string> split(string s, string sep){
    string act = "";
    vector<string> res;
    for(int c=0;c<s.size();c++) {
        bool split = false;
        for(int c2=0;c2<sep.size();c2++) {
            if(sep[c2] == s[c]) {
                split = true;
                break;
            }
        }
        if(split)  {
            res.push_back(act);
            act = "";
        } else {
            act = act + s[c];
        }
    }
    res.push_back(act);
    return res;
}
 
string removeChars(string s, string filters) {
    string res = "";
    for(int c=0;c<s.size();c++) {
        bool fine = true;
        for(int c2=0;c2<filters.size();c2++)  {
            if(filters[c2] == s[c]){
                fine = false;
                break;
            }
        }
        if(fine) res = res + s[c];
    }
    return res;
}
 
string replaceChars(string s, string from, string to) {
    for(int c=0;c<s.size();c++) {
        for(int c2=0;c2<from.size();c2++) {
            if(from[c2] == s[c]) {
                s[c] = to[c2%to.size()];
                break;
            }
        }
    }
    return s;
}
 
int main() {
    int n,m;
    cin>>n>>m;
    vector<long long int> rows(n);
    vector<long long int> cols(m);
 
    long long int allCols = 0;
    long long int allRows = 0;
 
    for(int c=0;c<n;c++) cin>>rows[c];
    for(int c=0;c<m;c++) cin>>cols[c];
 
    for(int c=0;c<n;c++) allRows ^= rows[c];
    for(int c=0;c<m;c++) allCols ^= cols[c];
 
    if(allRows != allCols) {
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<endl;
 
    vector<vector<int> > res(n,vector<int>(m,0));
 
    res[0][0] = allCols ^ rows[0] ^ cols[0];
    for(int c =1;c<rows.size();c++) {
        res[c][0] = rows[c];
    }
    for(int c=1;c<cols.size();c++){
        res[0][c] = cols[c];
    }
 
    for(int c=0;c<res.size();c++) {
        for(int c2=0;c2<res[c].size();c2++) {
            cout<<res[c][c2]<<" ";
        }
        cout<<endl;
    }
 
}