#include <iostream>
#include <map>
 
using namespace std;
 
int main() {
    string s;
    cin>>s;
    map<char,int> m;
    for(int c=0;c<s.size();c++) m[s[c]]++;
    map<char,int> m2;
    s = "Bulbasaur";
    for(int c=0;c<s.size();c++) m2[s[c]]++;
    int mini = 1e15;
    for(auto it = m2.begin(); it != m2.end(); it++) {
        mini = min(mini, m[it->first]/it->second);
    }
    cout<<mini;
}