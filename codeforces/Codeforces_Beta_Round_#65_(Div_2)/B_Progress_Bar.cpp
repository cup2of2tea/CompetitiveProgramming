#include <iostream>
 
using namespace std;
 
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int truc=a*b*c/100;
    for(int c2=0;c2<a;c2++)
    {
        if(b<truc)
        {
            cout<<b;
            truc-=b;
        }
        else
        {
             cout<<truc;
             truc=0;
         }
         cout<<" ";
     }
}
        