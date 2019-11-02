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
    vector<long long int> v(N);
    for(int c=0;c<N;c++) {
        cin>>v[c];
    }
 
 
   long long tot = 0;
   for(int c=0;c<v.size();c++) tot += v[c];
    long long maxi = *max_element(v.begin(),v.end());
 
    if(tot % 2 == 0 && maxi <= tot / 2) {
        cout<<"YES";
    } else {
        cout<<"NO";
    }
}
 