#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
 
typedef long long ll;
 
struct point
{
    double x;
    double y;
    point(){}
    point(double a,double b):x(a),y(b){}
};
 
 
double Pi = 4.0 * atan(1.0);
 
double angle(point p)
{
    return atan2(p.y,p.x)*180.0/Pi;
}
 
 
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    int S;
    cin>>S;
 
    vector<pair<int,point> > v(S);
    for(int c=0;c<S;c++)
    {
        v[c].first = c;
        cin>>v[c].second.x>>v[c].second.y;
    }
    vector<double> angles(v.size());
 
    for(int c=0;c<v.size();c++)
    {
        angles[c] = angle(v[c].second);
    }
    sort(angles.begin(),angles.end());
    double res = 360;
    if(v.size()==1) res = 0;
    for(int c=0;c<v.size();c++)
    {
        double a1 = angles[c];
        double a2 = angles[(c+1)%v.size()];
        double diff = a2-a1;
        if(diff < 0) diff+=360.0;
        res = min(res,360.0-diff);
    }
    if(res >= 360.0) res = 0;
    cout<<fixed<<setprecision(10)<<res;
    return 0;
}