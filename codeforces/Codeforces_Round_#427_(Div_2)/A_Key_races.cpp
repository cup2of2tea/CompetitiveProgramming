#include <iostream>
 
using namespace std;
 
int main() {
    int s,v1,v2,t1,t2;
    cin>>s>>v1>>v2>>t1>>t2;
    int tot1 = s*v1+t1*2;
    int tot2 = s*v2+t2*2;
    if(tot1 == tot2) {
        cout<<"Friendship";
    } else if(tot1 < tot2) {
        cout<<"First";
    } else {
        cout<<"Second";
    }
}