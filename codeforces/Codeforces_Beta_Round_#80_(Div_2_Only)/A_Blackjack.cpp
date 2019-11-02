#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n>21||n<=10)
        cout<<0;
    else if(n==20)
        cout<<15;
    else cout<<4;
    
}