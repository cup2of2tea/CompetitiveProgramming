#include <iostream>
 
using namespace std;
 
int main()
{
    int p1,p2,p3,p4,a,b;
    cin>>p1>>p2>>p3>>p4>>a>>b;
        int total=0;
        for(int c=a;c<=b;c++)
        {
                if(c==(((c%p1)%p2)%p3)%p4)
                        total++;
        }
        cout<<total;
}