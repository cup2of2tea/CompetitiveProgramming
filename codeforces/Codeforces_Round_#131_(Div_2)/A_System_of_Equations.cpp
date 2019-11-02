#include <iostream>
using namespace std;
 
int main()
{
    int n,m;
    cin>>n>>m;
    int res=0;
    for(int c=0;c<100;c++)
        for(int c2=0;c2<100;c2++)
            res+=(c*c+c2==n&&c2*c2+c==m?1:0);
    cout<<res;
}