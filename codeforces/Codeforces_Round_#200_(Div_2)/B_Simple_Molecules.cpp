#include <iostream>
 
using namespace std;
 
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    for(int i=0;i<=a;i++)
    {
        int a2=a-i;
        int b2=b-i;
        int j=a2;
        int c2=c-j;
        if(b2==c2&&b2>=0&&a2>=0)
        {
            cout<<i<<" "<<b2<<" "<<j;
            return 0;
        }
    }
    cout<<"Impossible";
}