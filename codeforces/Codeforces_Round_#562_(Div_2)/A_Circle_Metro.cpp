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
 
    int n,a,x,b,y;
    cin>>n>>a>>x>>b>>y;
 
 
    while(1) {
        a++;
        b--;
        if(b==0) b = n;
        if(a==n+1) a=1;
        if(a==b) {
            cout<<"YES";
            return 0;
        }
        if(a==x || b == y) break;
    }
    cout<<"NO";
 
}