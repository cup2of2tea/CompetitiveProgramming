#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
 
using namespace std;
 
 
int main() {
    ios_base::sync_with_stdio(false);
    int a1, a2, k, k2, n;
    cin>>a1>>a2>>k>>k2>>n;
 
    int one = 0;
    int  mini = 1e8;
    int  maxi = 0;
    for(int c=0;c<=a1*k;c++) {
        if(c > n) break;
        int z = c/k;
        int n2 = n - c;
        if(n2 < 0) continue;
        if(k2*a2 < n2) continue;
//        cout<<n2<<" "<<c<<" "<<n2/k2<<endl;
        maxi = max(maxi, min(a2,n2/k2)+z);
    }
 
 
    n -= max(0,k-1)*a1+max(0,k2-1)*a2;
 
    mini =max(0,n);
    cout<<mini<<" "<<maxi<<endl;
}