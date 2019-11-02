#include <iostream>
#include <map>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    string a,b;
    cin>>a>>b;
    int n1=0,n2=0;
    for(int c=0;c<a.size();c++)
        n1 += a[c]-'0';
    for(int c=0;c<b.size();c++)
        n2 += b[c]-'0';
    cout<<((n1+n1%2) >= n2 ? "YES":"NO");
}