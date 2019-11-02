#include <iostream>
 
using namespace std;
 
int main()
{
    int n;
    cin>>n;
    
    for(int c=0;c<n;c++)
    {
        int z;
        cin>>z;
        cout<<max(z-2,0)<<endl;
    }
}