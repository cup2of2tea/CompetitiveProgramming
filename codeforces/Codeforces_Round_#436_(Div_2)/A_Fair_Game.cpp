#include <iostream>
#include <map>
 
 
using namespace std;
 
int main() {
    map<int,int> m;
    int n;
    cin>>n;
    int mini = 1e8;
    int maxi = -1e8;
    for(int c=0;c<n;c++){
        int z;
        cin>>z;
        m[z]++;
        mini = min(mini, z);
        maxi = max(maxi, z);
    } 
    if(m[mini] == n/2 && m[maxi] == n/2) {
        cout<<"YES\n"<<mini<<" "<<maxi;
    } else {
        cout<<"NO";
    }
}