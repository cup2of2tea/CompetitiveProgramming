#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <fstream>
#include <queue>
#include <iomanip>
#include <cmath>
using namespace std;
typedef long long ll;
 
int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin>>N;
    vector<long long int> v(N);
    map<long long int, long long int> compte;
    for(int c=0;c<N;c++) {
        cin>>v[c];
        compte[v[c]]++;
    }
 
    long long toRemove = 0;
    for(auto z:compte) {
        compte[z.first]--;
        toRemove+=max(0LL,z.second-1);
    }
 
    long long best = 1e8;
 
    for(int c=0;c<N;c++) {
        long long removed = 0;
        int c2;
        for(c2=c;removed < toRemove && c2<N;c2++) {
            removed += (compte[v[c2]]?1:0);
            compte[v[c2]]--;
        }
        c2--;
        if(removed==toRemove) {
            best = min(best, static_cast<long long>((c2-c)+1));
        }
        while(c2 >= c) {
            compte[v[c2]]++;
            c2--;
        }
    }
    cout<<best<<endl;
}
 