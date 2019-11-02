#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
 
using namespace std;
 
void verify(string s1, string s2) {
    string bla = "";
    for(int c=0;c<s2.size();c++) if(s2[c]=='1') bla = bla + s1[c];
    for(int c=0;c<s2.size();c++) if(s2[c]=='2') bla = bla + s1[c];
    for(int c=0;c+1<bla.size();c++) {
        if(bla[c]>bla[c+1]) {
            cout<<"wtf "<<bla<<" "<<s1<<" "<<s2<<endl;
        }
    }
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
 
    int t;
    cin>>t;
    while(t--) {
        //int n=rand()%6+3;
        int n;
        cin>>n;
        string s;
        //for(int c=0;c<n;c++) s = s+string(1,((char)('0')+rand()%5));
        cin>>s;
        int prevCol1 = '0';
        int prevCol2 = '0';
 
        char miniCol2 = '9';
        char maxiCol1 = '0';
 
        multiset<char> q;
        for(int c=0;c<s.size();c++) {
            q.insert(s[c]);
        }
 
        bool ok = true;
 
        string res = s;
 
        for(int c=0;c<s.size();c++) {
            char mini = (*q.begin());
            if(mini == s[c] && mini <= miniCol2){
                prevCol1 = s[c];
                res[c]='1';
                maxiCol1 = max(maxiCol1, s[c]);
            } else if(prevCol2 > s[c]){
                ok = false;
                break;
            } else {
                res[c]='2';
                prevCol2 = s[c];
                miniCol2 = min(miniCol2, s[c]);
            }
 
            q.erase(q.find(s[c]));
        }
        if(miniCol2 < maxiCol1) ok = false;
        //if(ok) {
        //    verify(s,res);
        //}
        //cout<<s<<" "<<res<<endl;
        cout<<(ok?res:"-")<<endl;
    }
}