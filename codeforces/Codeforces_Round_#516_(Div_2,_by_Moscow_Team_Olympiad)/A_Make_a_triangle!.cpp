#include <bits/stdc++.h>
 
 
using namespace std;
 
int main() {
    vector<int> v(3);
    cin>>v[0]>>v[1]>>v[2];
 
    int maxi = (*max_element(v.begin(),v.end()));
    int sum = v[0]+v[1]+v[2];
    sum -= maxi;
 
    cout<<max(maxi-sum+1,0);
 
}