#include<iostream>
using namespace std;
int main()
{
    long long n,m,s;
    cin>>n>>m>>s;
    cout<<(((n-1)%s)+1)*(((m-1)%s)+1)*((n-1)/s+1)*((m-1)/s+1);
}