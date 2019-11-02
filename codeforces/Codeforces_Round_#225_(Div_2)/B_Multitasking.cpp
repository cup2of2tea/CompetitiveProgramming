#include <iostream>
 
using namespace std;
 
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    cout<<(m*(m-1)/2)<<endl;
    for(int c=1;c<=m;c++)
        for(int c2=c+1;c2<=m;c2++)
            if(!k) cout<<c<<" "<<c2<<endl;
            else cout<<c2<<" "<<c<<endl;
}