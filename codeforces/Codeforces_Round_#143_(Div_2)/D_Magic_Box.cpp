#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <cstdio>
#include <set>
#include <stack>
#include <ctime>
#include <climits>
#include <iterator>
#define LOCAL
#ifdef ONLINE_JUDGE
#define COUT(s)
#undef LOCAL
#endif
 
 
#ifdef LOCAL
#define cin in
//#define cout out
#define COUT(s) cout<<"-----"<<s<<endl;
#endif
#define MOD 10000009
 
#define FOREACH(i, n) for (typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
#define MEMSET(p, c) memset(p, c, sizeof(p))
using namespace std;
 
struct point
{
    point(){}
    point(double a,double b,double c):x(a),y(b),z(c){}
    double x;
    double y;
    double z;
};
 
int main()
{
    #ifdef LOCAL
        ifstream in("input.txt");
        ofstream out("output.txt");
    #endif
    int x,y,z;
    cin>>x>>y>>z;
    double x1,y1,z1;
    cin>>x1>>y1>>z1;
    vector<point> v;
    v.push_back(point(x1/2.0,0,z1/2.0));    //a1
    v.push_back(point(x1/2.0,y1,z1/2.0));   //a2
    v.push_back(point(x1/2.0,y1/2.0,0));    //a3
    v.push_back(point(x1/2.0,y1/2.0,z1));   //a4
    v.push_back(point(0,y1/2.0,z1/2.0));    //a5
    v.push_back(point(x1,y1/2.0,z1/2.0));   //a6
    vector<int> score(6);
    for(int c=0;c<6;c++)
        cin>>score[c];
    int res=0;
    for(int c=0;c<6;c++)
    {
        double x2=x,y2=y,z2=z;
        while(abs(x2-v[c].x)>0.01||abs(y2-v[c].y)>0.01||abs(z2-v[c].z)>0.01)
        {
            if(x2<=x1&&x2>=0&&y2<=y1&&y2>=0&&z2<=z1&&z2>=0)
            {
                goto end;
            }
            x2=(x2+v[c].x)/2;
            y2=(y2+v[c].y)/2;
            z2=(z2+v[c].z)/2;
        }
        res+=score[c];
        end:;
    }
    cout<<res;
}