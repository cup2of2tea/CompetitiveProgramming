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
    int N;
    cin>>N;
    int neg = 0;
    int zero = 0;
 
    long long res = 0;
    for(int c=0;c<N;c++) {
        long long  z;
        cin>>z;
        if(z == 0) zero++;
        else if(z<0) {
            neg++;
            res += (-1-z);
        } else {
            res += z-1;
        }
    }
    if(neg % 2 == 1 && !zero) {
        res += 2;
    }
    res += zero;
    cout<<res<<endl;
}
 