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
 
    int T;
    cin>>T;
    while(T--) {
        long long int a,b;
        cin>>a>>b;
        long long int n;
        cin>>n;
 
        for(int c=0;c<min(n,3LL);c++) {
            long long tmp = a^b;
            a = b;
            b = tmp;
        }
        n -= min(3LL,n);
        n%=3;
        for(int c=0;c<n;c++) {
            long long tmp = a^b;
            a=b;
            b=tmp;
        }
        cout<<a<<endl;
    }
}
 