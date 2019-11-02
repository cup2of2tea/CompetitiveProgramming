#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
 
int main() {
    int N;
    cin>>N;
    vector<bool> isPrime(1e6,true);
    vector<int> v(N);
    for(int c=0;c<N;c++) {
        cin>>v[c];
    }
    sort(v.begin(),v.end());
    map<int,int> m;
    for(int c=0;c<v.size();c++) {
        int act = v[c];
        for(int c=2;c*c<=act;c++) {
            if(act%c == 0) m[c]++;
            while(act%c==0) act/=c;
        }
        if(act > 1) m[act]++;
    }
    int maxi = 1;
    for(auto &n:m){
        maxi = max(maxi,n.second);
    }
    cout<<maxi;
}