#include <iostream>
#include <vector>
#include <climits>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstring>
 
using namespace std;
int main()
{
    int a;
    int x,y;
    cin >> a >> x >> y;
    if ( x >= a || x <= -a ) {
       cout << -1 << endl;
       return 0;
    }
    if ( y % a == 0 ) {
       cout << -1 << endl;
       return 0;  
    }
    y=y/a+1;
    if ( y == 1 || y == 2 ) {
         if ( x < (a+1)/2 && x > (-a-1)/2 ) { 
            cout << y << endl;
            return 0;
         }
    }
    else if ( y % 2 == 0 ) {
         if ( x < (a+1)/2 && x > (-a-1)/2 ) {
            cout << (y/2)*3-1 << endl;
            return 0;
         }
    }
    else {
         if ( x > -a && x < 0 ) {
              cout << ( (y-1)/2)*3 << endl;
              return 0;
         }
         else if ( x < a && x > 0 ) {
              cout << (y-1)/2*3+1 << endl;
              return 0;
         }
    }
    cout << -1 << endl;
    return 0;
}
    