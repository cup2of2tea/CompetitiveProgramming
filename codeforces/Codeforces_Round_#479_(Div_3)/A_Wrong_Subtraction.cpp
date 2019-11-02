#include <iostream>
using namespace std;
 
int main() {
    long long N,k;
    cin>>N>>k;
    for(int c=0;c<k;c++) {
        if(N%10==0) N/=10;
        else N--;
    }
    cout<<N;
}