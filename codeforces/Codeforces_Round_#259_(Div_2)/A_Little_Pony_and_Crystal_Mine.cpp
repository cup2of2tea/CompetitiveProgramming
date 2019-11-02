#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
 
 
 
int main()
{
    int n;
    cin>>n;
    for(int c=0;c<n;c++)
    {
        for(int c2=0;c2<n;c2++)
        {
            if(abs(c2-(n)/2) <= (n/2-abs(c-(n/2))))
            {
                cout<<"D";
            }
            else cout<<"*";
        }
        cout<<endl;
    }
 
    return 0;
}