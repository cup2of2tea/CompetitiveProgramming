#include <iostream>
using namespace std;
 
int main()
{
    int al,ar,bl,br;
    cin>>al>>ar>>bl>>br;
    if((al*2+3>br&&br+1>=al)||(ar*2+3>bl&&bl+1>=ar))
        cout<<"YES";
    else
        cout<<"NO";
}