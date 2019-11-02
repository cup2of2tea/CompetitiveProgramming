#include <iostream>
#include <vector>
 
using namespace std;
 
int main()
{
    int N,M;
    cin>>N>>M;
    if(N==1) cout<<1;
    else if(M >= N-M+1){
        cout<<M-1;
    }
    else {
        cout<<M+1;
    }
}