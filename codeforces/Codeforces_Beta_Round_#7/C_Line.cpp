#include <iostream>  
#include <fstream>  
#include <sstream>
#include <cmath>  
#include <algorithm>
#include <string>  
#include <vector>    
#include <list>  
#include <map>  
#include <set>  
#include <queue>  
#include <deque>
#include <stack>  
#include <bitset>
 
using namespace std;
long long gcd (long long a, long long b, long long & x, long long & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    long long x1, y1;
    long long d = gcd (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
int main () {
    long long a, b, c;
    cin >> a >> b >> c;
    long long x, y;
    long long d = gcd(a, b, x, y);
    if(c % d != 0) {
        cout << -1 << endl;
    }
    else {
        cout << -x *  (c / d) << " " << -y * (c / d) << endl;
    }
    return 0;
}