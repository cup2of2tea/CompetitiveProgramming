#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <map>
#include <cstdio>
#include <set>
#include <ctime>
#include <queue>
#include <climits>
#include <iomanip>
#include <iterator>
#include <stack>
#define LOCAL
#ifdef ONLINE_JUDGE
#undef LOCAL
#endif
 
 
 
#ifdef LOCAL
#define cin in
#endif
#define FOREACH(i, n) for (typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
 
using namespace std;
 
 
int main()
{
#ifdef LOCAL
    ifstream cin("input.txt");
#endif
    double a,b,m,vx,vy,vz;
    cin>>a>>b>>m>>vx>>vy>>vz;
    if(vz<0)
        vz=-vz;
    vx/=abs(vy);
    vz/=abs(vy);
    double xact=a/2.0,yact=m,zact=0;
    while(1)
    {
        double pente_z=zact-(zact+vz);
        double diff_z=zact-pente_z*yact;
        double pente_x=xact-(xact+vx);
        double diff_x=xact-pente_x*yact;
        double y_sol_x=-1;
        if(vx>0)
        {
            y_sol_x=(a-diff_x)/pente_x;
        }
        else if(vx<0)
        {
            y_sol_x=(-diff_x)/pente_x;
        }
        double y_sol_z=-1;
        if(vz>0)
        {
            y_sol_z=(b-diff_z)/pente_z;
        }
        else if(vz<0)
        {
            y_sol_z=(-diff_z)/pente_z;
        }
        if(y_sol_x<=0&&y_sol_z<=0)
        {
            cout<<fixed<<setprecision(12)<<diff_x<<" "<<diff_z<<endl;
            return 0;
        }
        else if(y_sol_x>=y_sol_z)
        {
            if(vx>0)
                xact=a;
            else xact=0;
            vx=-vx;
            if(y_sol_x==y_sol_z){
                if(vz>0)
                    vz=b;
                else
                    vz=0;
                vz=-vz;
            }
            else
            {
                zact=y_sol_x*pente_z+diff_z;
            }
        }
        else
        {
            if(vz>0)
                zact=b;
            else
                zact=0;
            xact=y_sol_z*pente_x+diff_x;
            vz=-vz;
        }
        yact=max(y_sol_x,y_sol_z);
    }
}