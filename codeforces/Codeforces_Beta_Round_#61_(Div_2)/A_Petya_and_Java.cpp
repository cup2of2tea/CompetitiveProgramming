#include <iostream>
 
using namespace std;
 
 
int main()
{
    long double nb;
    cin>>nb;
    if(nb<=127)
        cout<<"byte";
    else if(nb<=32767)
        cout<<"short";
    else if(nb<=2147483647)
        cout<<"int";
    else if(nb<=9223372036854775807LL)
        cout<<"long";
    else
        cout<<"BigInteger";
 
}