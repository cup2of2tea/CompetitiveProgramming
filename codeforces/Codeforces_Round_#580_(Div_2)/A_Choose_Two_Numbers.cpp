#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <fstream>
 
using namespace std;
 
long long pgcd(long long a, long long b) {
    return a==0?b:pgcd(b%a,a);
}
 
int main() {
    int N,M;
    cin>>N;
    vector<int> v(N);
    for(int c=0;c<N;c++) {
        cin>>v[c];
    }
    cin>>M;
    vector<int> v2(M);
    for(int c=0;c<M;c++) {
        cin>>v2[c];
    }
    cout<<(*max_element(v.begin(),v.end()))<<" "<<(*max_element(v2.begin(),v2.end()));
}
 