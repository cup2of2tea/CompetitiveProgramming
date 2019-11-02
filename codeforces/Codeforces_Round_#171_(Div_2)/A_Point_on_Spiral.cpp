#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
 
 
int main()
{
    int x,y;
    cin>>x>>y;
    int xact=0,yact=0;
    int etape=0;
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    while(1)
    {
        int x2=xact+dx[etape%4]*(etape+2)/2;
        int y2=yact+dy[etape%4]*(etape+2)/2;
        if(x>=min(xact,x2)&&x<=max(xact,x2)&&y>=min(yact,y2)&&y<=max(yact,y2))
        {
            cout<<etape;
            return 0;
        }
        etape++;
        xact=x2;
        yact=y2;
    }
}