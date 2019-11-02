#include <iostream>
#include <map>
#include <vector>
 
using namespace std;
 
int main() {
    map<int,int> count;
    int n;
    cin>>n;
    vector<int> v(n);
    for(int c=0;c<v.size();c++) {
        cin>>v[c];
        count[v[c]]++;
    }
 
    map<int,bool> seen;
 
    int act = 1;
    int res = 0;
    while(count[act] != 0) {
        act++;
    }
    for(int c=0;c<n;c++) {
        if(count[v[c]] != 1 && act!=v[c] && (seen[v[c]] || act < v[c])) {
            while(count[act] != 0) {
                act++;
            }
            count[v[c]]--;
                count[act]++;
            v[c] = act;
            while(count[act] != 0) {
                act++;
            }
            res++;
        }
        seen[v[c]]=true;
    }
    cout<<res<<endl;
    for(int c=0;c<v.size();c++) cout<<v[c]<<" ";
}