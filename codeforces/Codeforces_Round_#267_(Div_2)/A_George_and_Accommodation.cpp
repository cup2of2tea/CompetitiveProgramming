#include <iostream>
 
using namespace std;
 
int main()
{
    int n;
    cin>>n;
    int res = 0;
    for(int c=0;c<n;c++)
    {
        int a,b;
        cin>>a>>b;
        res+=(b-a>=2?1:0);
    }
    cout<<res;
}