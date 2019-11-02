#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
int main()
{
        int n;
        int x,y;
        cin>>n>>x>>y;
        if(n==2)
        {
                cout<<"NO";
                return 0;
        }
        if((x!=n/2&&x!=n/2+1)||(y!=n/2&&y!=n/2+1))
        {
                cout<<"YES";
                return 0;
        }
        if((x==n/2||x==n/2+1)&&(y==n/2||y==n/2+1))
        {
                cout<<"NO";
                return 0;
        }
        cout<<"YES";
}