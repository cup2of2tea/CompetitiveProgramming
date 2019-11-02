#include <iostream>
 
using namespace std;
 
int main() {
    int T,S,Q;
    cin>>T>>S>>Q;
    int act = 0;
    while(S<T) {
        S*=Q;
        act++;
    }
    cout<<max(act,1);
 
}