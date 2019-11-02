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
    int N,M;
    cin>>N>>M;
    vector<string> v(N);
    for(int c=0;c<N;c++) {
        cin>>v[c];
    }
    vector<int> points(M);
    vector<int>counts(5);
    long long res = 0;
    for(int c=0;c<M;c++) cin>>points[c];
    for(int c=0;c<M;c++) {
        for(int c2=0;c2<5;c2++) {
            counts[c2]=0;
        }
        for(int c2=0;c2<N;c2++) {
            counts[v[c2][c]-'A']++;
        }
        res += (*max_element(counts.begin(),counts.end()))*points[c];
    }
    cout<<res;
}