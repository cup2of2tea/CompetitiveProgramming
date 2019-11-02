#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
    int n;
    cin>>n;
    vector<int> v(2*n);
    for(int c=0;c<2*n;c++) cin>>v[c];
    sort(v.begin(),v.end());
    if(v[0] == v.back()) {
        cout<<-1;
        return 0;
    }
    for(int c=0;c<v.size();c++) cout<<v[c]<<" ";
    
}