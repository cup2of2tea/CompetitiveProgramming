#include <iostream>
using namespace std;
 
int main()
{
    int r[3];
    for(int c=0;c<3;c++)
        cin>>r[c];
    int total=29;
    int periode=0;
    while(r[0]!=0||r[1]!=0||r[2]!=0)
    {
        r[periode]=max(0,r[periode]-2);
        periode=(periode+1)%3;
        total++;
    }
    cout<<total;
}