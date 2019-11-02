#include <iostream>
using namespace std;
int main() {
    long long int n,a,b,c,d;
    cin>>n>>a>>b>>c>>d;
    long long int mini = min(min(a+b,a+c),min(c+d,d+b));
    long long int maxi = max(max(a+b,a+c),max(c+d,d+b));
    
    long long int ecart = n-(maxi-mini);
    cout<<max(0LL,ecart*n);
}