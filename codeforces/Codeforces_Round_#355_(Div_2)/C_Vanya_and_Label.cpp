#include <bits/stdc++.h>
using namespace std;
 
 
 
int main()
{
#ifndef ONLINE_JUDGE
//    #define cin in
//    ifstream in("input.txt");
#endif // ONLINE_JUDGE
    string possibilities = "";
    map<char,int> m;
    for(char c='0';c<='9';c++) {
        possibilities+=c;
        m[c] = c-'0';
    }
    for(char c='A';c<='Z';c++) {
        possibilities+=c;
        m[c] = c-'A'+10;
    }
    for(char c='a';c<='z';c++) {
        possibilities+=c;
        m[c] = c-'a'+36;
    }
    possibilities+="-_";
    m['-'] = 62;
    m['_'] = 63;
 
    map<char,int> compte;
 
    for(int c=0;c<possibilities.size();c++)
        for(int c2=0;c2<possibilities.size();c2++)
            for(int c3=0;c3<possibilities.size();c3++)
 
                if((m[possibilities[c3]] & m[possibilities[c2]]) == m[possibilities[c]])
                    compte[possibilities[c]]++;
 
    string s;
    cin>>s;
    long long res = 1;
    for(int c=0;c<s.size();c++) {
        res*=compte[s[c]];
        res%=(long long)(1e9+7);
    }
    cout<<res;
}