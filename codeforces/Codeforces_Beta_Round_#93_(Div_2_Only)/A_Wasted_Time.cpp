#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <sstream>
 
using namespace std;
 
double dist(double a,double b,double c,double d) {
           double res=((a-c)*(a-c));
           res+=((b-d)*(b-d));
           
           res=sqrt(res);
           return res;
}
int main()
{
    int n;
    double k;
    double res=0;
    cin >> n >> k;
    double a,b,c,d;
    for ( int i = 0; i < n; i++ ) {
        if ( i == 0 ) {
           cin >> a >> b;
           continue;
        }
        c=a;
        d=b;
        cin >> a >> b;
//        cout << a << b << c << d << endl;
        res+=dist(a,b,c,d);
  //      cout << res << endl;
    }
    res/=50.0;
    res*=k;
        printf("%.9f\n",res);
//    system("pause");
    return 0;
}
 