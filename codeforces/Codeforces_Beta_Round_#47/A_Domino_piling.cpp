#include <iostream>
 
using namespace std;
 
int main()
{
    unsigned long long int N,M;
    cin>>N>>M;
    if(N%2==0||M%2==0)
        cout<<M*N/2;
    else
        cout<<(M-1)*N/2+(N-1)/2;
}