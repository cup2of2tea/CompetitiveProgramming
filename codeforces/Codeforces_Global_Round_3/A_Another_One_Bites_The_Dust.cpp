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
    long long int a,b,c;
    cin>>a>>b>>c;
 
    if(a==b) {
        cout<<a+b+c*2<<endl;
    } else {
        cout<<min(a,b)*2+1+c*2;
    }
 
 
 
}