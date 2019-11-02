#include <iostream>
 
using namespace std;
 
int main()
{
    int n1,n2,n3;
    cin>>n1>>n2>>n3;
    for(int c=1;c<=n1;c++)
    {
        int c2,c3;
        if(n1%c==0)
        {
            c2=n1/c;
            if(n2%c==0)
            {
               c3=n2/c;
               if(c2*c3==n3)
               {
                   cout<<(c+c2+c3)*4;
                   return 0;
               }
           }
        }
    }
}        