#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    int a,b;
    cin>>a>>b;
    int z=max(a,b);
    if(z==1)
        cout<<"1/1";
    else if(z==2)
        cout<<"5/6";
    else if(z==3)
        cout<<"2/3";
    else if(z==4)
        cout<<"1/2";
    else if(z==5)
        cout<<"1/3";
    else cout<<"1/6";
}