#include <iostream>
 
using namespace std;
 
int main() {
    long long one = 0, two = 0;
    long long int n,b;
    cin>>n>>b;
    for(int c=0;c<n;c++){
        long long int z;
        cin>>z;
        one*=b;
        one+=z;
    }
    cin>>n>>b;
    for(int c=0;c<n;c++) {
        long long int z;
        cin>>z;
        two*=b;
        two+=z;
    }
    if(one == two) cout<<"=";
    if(one < two) cout<<"<";
    if(one > two) cout<<">";
}