#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
 
 
 
int main() {
    int n;
    cin>>n;
    vector<string> v(n);
    for(int c=0;c<n;c++) cin>>v[c];
    vector<vector<int> > compte(v.size(),vector<int>(26,0));
    for(int c=0;c<v.size();c++) for(int c2=0;c2<v[c].size();c2++) compte[c][v[c][c2]-'a']++;
    int res = 0;
    for(int c=0;c<26;c++)
        for(int c2=0;c2<26;c2++)
        {
            int act = 0;
            for(int c3=0;c3<compte.size();c3++)
            {
                int z =compte[c3][c] + (c!=c2?compte[c3][c2]:0);
                if(z == v[c3].size()) act+=z;
            }
            res = max(res,act);
        }
    cout<<res;
}