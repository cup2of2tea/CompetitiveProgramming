#include <iostream>
#include <map>
#include <vector>
#include <fstream>
 
using namespace std;
 
long long pgcd(long long a, long long b) {
    return a==0?b:pgcd(b%a,a);
}
 
int main() {
    long long n,m;
    cin>>n>>m;
 
    long long p = pgcd(n,m);
 
    //cout<<p<<endl;
 
    int q;
    cin>>q;
    while(q--) {
        long long int sx, sy, ex, ey;
        cin>>sx>>sy>>ex>>ey;
        sy --;
        ey--;
        long long t1 = 0, t2 = 0;
        if(sx == 1) {
            t1 = sy/(n/p);
        } else {
            t1 = sy/(m/p);
        }
 
        if(ex == 1) {
            t2 = ey/(n/p);
        } else {
            t2 = ey/(m/p);
        }
 
        //cout<<t1<<" "<<t2<<endl;
 
        if(t1 == t2) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
 
    }
}