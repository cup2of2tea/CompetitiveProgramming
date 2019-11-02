#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    int n;
    cin>>n;
    vector<int> x(n);
    vector<int> y(n);
    for(int c=0;c<n;c++)
        cin>>x[c]>>y[c];
    int res=0;
    for(int c=0;c<n;c++)
    {
        bool left=false,right=false,up=false,bot=false;
        int c2;
        for(c2=0;c2<n;c2++)
        {
            if(c==c2)
                continue;
            if(x[c]==x[c2])
            {
                if(y[c2]<y[c])
                    bot=true;
                else if(y[c2]>y[c])
                    up=true;
            }
            else if(y[c]==y[c2])
            {
                if(x[c2]<x[c])
                    left=true;
               else if(x[c2]>x[c])
                   right=true;
            }
       }
       if(left&&right&&up&&bot)
           res++;
   }
   cout<<res;
}