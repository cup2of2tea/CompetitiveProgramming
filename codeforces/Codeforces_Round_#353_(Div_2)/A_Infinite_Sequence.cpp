#include <iostream>
 
using namespace std;
 
int main() {
    long long a,b,c;
    cin>>a>>b>>c;
    if(a > b && c >= 0 || a < b && c <= 0){
        cout<<"NO";
        return 0;
    }
    if(c==0) {
        if(a==b) {
            cout<<"YES";
        }
        else
        cout<<"NO";
        return 0;
    }
    
 
    cout<<((abs(b - a) % abs(c) == 0)?"YES":"NO");
} 