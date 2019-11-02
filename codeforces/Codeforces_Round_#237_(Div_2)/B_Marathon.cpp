#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <iterator>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
 
int main()
{
    double a,d;
    scanf(" %lf %lf",&a,&d);
    int z = d/(4*a);
    d-=(double)z*(4*a);
    int n;
    scanf(" %d",&n);
    double act = 0;
    for(int c=0;c<n;c++)
    {
        double xres,yres;
        act+=d;
        if(act >= 4*a) act-=4*a;
        if(act <= a)
        {
            xres=act;
            yres=0;
        }
        else if(act <=2*a)
        {
            xres = a;
            yres = act-a;
        }
        else if(act <= 3*a)
        {
            yres = a;
            xres = 3*a-act;
        }
        else
        {
            xres = 0;
            yres = 4*a-act;
        }
        printf("%f %f\n",xres,yres);
    }
}