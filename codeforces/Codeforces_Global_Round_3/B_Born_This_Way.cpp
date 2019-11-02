#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>
#include <set>
#include <chrono>
 
using namespace std;
 
 
int main() {
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    long long ta,tb,k;
    cin>>ta>>tb>>k;
 
    vector<long long int> v1(n);
    for(int c=0;c<n;c++) {
        cin>>v1[c];
        v1[c]+=ta;
    }
    sort(v1.begin(),v1.end());
 
    vector<long long int> v2(m);
    for(int c2=0;c2<m;c2++) {
        cin>>v2[c2];
    }
    sort(v2.begin(),v2.end());
 
    int i = 0;
 
    long long best = -1;
 
 
    int j = 0;
    if(k>=v1.size() || k >= v2.size()) {
        cout<<-1;
        return 0;
    }
    for(int c=0;c<v1.size()&&c<=k;c++) {
        while(j<v2.size()&&v2[j] < v1[c]) {
            j++;
        }
        if(j+k-c>=v2.size()) {best=-1;break;}
        best = max(best, v2[j+k-c]+tb);
    }
    cout<<best;
}