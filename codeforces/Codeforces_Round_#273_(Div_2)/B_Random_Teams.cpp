#include <iostream>
 
using namespace std;
 
int main() {
    long long a,b;
    cin>>a>>b;
    cout<<((a/b+1)*(a/b)*(a%b)+(a/b)*(a/b-1)*(b-a%b))/2<<" "<<(a-b+1)*(a-b)/2;
}