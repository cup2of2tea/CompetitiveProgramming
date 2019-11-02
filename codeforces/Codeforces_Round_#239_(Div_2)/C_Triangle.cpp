#include <iostream>
#include <cmath>
 
using namespace std;
 
 
int pgcd(int a,int b)
{
    return a==0?b:pgcd(b%a,a);
}
 
int main()
{
    int l1, l2 ;
    cin>>l1>>l2;
    int first,second;
    for(int c=1;c*c<l1*l1;c++)
    {
        if(c*c != l1*l1&&(double)(int)(sqrt((double)(l1*l1-c*c))) == (sqrt((double)(l1*l1-c*c))))
        {
            int x = c;
            int y = (sqrt((double)(l1*l1-c*c)));
            int x2 = -y;
            int y2 = x;
            int g = pgcd(x,y);
            x2 /= g;
            y2 /= g;
            if(l2*l2%(x2*x2+y2*y2)==0)
            {
                int toChange = sqrt((double)(l2*l2/(x2*x2+y2*y2)));
                if(toChange * toChange == (l2*l2/(x2*x2+y2*y2)) )
                {
                    x2 *= toChange;
                    y2 *= toChange;
                    if(x2!=0&&y2!=0&&x2!=x&&y2!=y&&x!=0&&y!=0)
                    {
                        cout<<"YES"<<endl;
                        cout<<"0 0"<<endl;
                        cout<<x<<" "<<y<<endl;
                        cout<<x2<<" "<<y2<<endl;
                        return 0;
                    }
                }
            }
        }
     }
     cout<<"NO";
 
}