#include <bits/stdc++.h>
using namespace std;
 
 
 
int main()
{
 
 
    int n,m,k;
    cin>>n>>m>>k;
    cout<<(n*m-2*(k-1))<<" ";
    int xact = 0,yact= 0;
    int dx = 1;
    for(int c=0;c<n*m-2*(k-1);c++)
    {
        cout<<xact+1<<" "<<yact+1<<" ";
        if(xact+dx >= n || xact+dx<0)
        {
            dx = -dx;
            yact++;
        }
        else
        {
            xact+=dx;
        }
    }
    for(int c2=0;c2<k-1;c2++)
    {
        cout<<endl<<2<<" ";
        for(int c=0;c<2;c++)
        {
            cout<<xact+1<<" "<<yact+1<<" ";
            if(xact+dx >= n || xact+dx<0)
            {
                dx = -dx;
                yact++;
            }
            else
            {
                xact+=dx;
            }
        }
    }
}