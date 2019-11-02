#include <iostream>
#include <map>
#include <vector>
#include <fstream>
 
using namespace std;
 
int main() {
    int T;
    cin>>T;
    while(T--) {
        long long n,m,k;
        cin>>n>>m>>k;
        long long int current;
        cin>>current;
        long long int bag = m;
        bool ok = true;
        for(int c=1;c<n;c++) {
            long long int z;
            cin>>z;
            /*if(z+bag < current-k){
                ok = false;
            }*/
            bag += max(0LL,current-max(0LL,z-k));
            bag -= max(0LL,(z-k)-current);
            if(bag < 0 ) {
                ok = false;
            }
            //cout<<current<<"->"<<z<<endl;
            current = z;
            //cout<<"="<<current<<" "<<bag<<endl;
        }
        if(ok) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
}