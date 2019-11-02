#include <iostream>
 
using namespace std;
 
int main()
{
    int d = 1;
    int n;
    cin>>n;
    long long int res = 0;
    long long int pow10 = 10;
    while(pow10 <= n)
    {
        res += (pow10 - (pow10 / 10))*d ;
        pow10 *= 10;
        d++;
    }
    res += (n + 1 - pow10 / 10)*d;
    cout<<res;
}