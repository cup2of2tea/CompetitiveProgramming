#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <fstream>
#include <cstring>
using namespace std;
 
const long long MOD = 1e9+7;
 
int main() {
    int N;
    cin>>N;
    long long K;
    cin>>K;
 
    vector<long long int> v(N);
    for(int c=0;c<N;c++) {
        cin>>v[c];
    }
    sort(v.begin(),v.end());
 
    long long act = v[v.size()/2];
    for(int c=v.size()/2+1;c<v.size();c++) {
        long long delta = min(v[c]-act,K/(c-v.size()/2));
 
        K -= delta *(c-v.size()/2);
        act += delta;
        if(act < v[c]) break;
    }
    if(act >= v.back()) {
        act += K/((v.size()-1)-(v.size()/2)+1);
    }
    cout<<act;
}
 