#include <bits/stdc++.h>
using namespace std;
 
 
int main()
{
    ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    //#define cin in
    //ifstream in("input.txt");
#endif // ONLINE_JUDGE
    int a1,b1,a2,b2,a3,b3;
    cin>>a1>>b1>>a2>>b2>>a3>>b3;
    for(int c=0;c<4;c++)
    {
        int x1=a2;
        int y1=b2;
        int x2=a3;
        int y2=b3;
        if(c&1)
        {
            swap(x1,y1);
        }
        if(c&2)
        {
            swap(x2,y2);
        }
        if((x1+x2 <= a1 && y1 <= b1 && y2 <= b1) || (y1+y2 <= b1 && x1 <= a1 && x2 <= a1))
        {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
}