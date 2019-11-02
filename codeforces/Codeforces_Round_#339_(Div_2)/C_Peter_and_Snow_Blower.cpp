 #include <bits/stdc++.h>
using namespace std;
#define M_PI           3.14159265358979323846
 
int belette(double a,double b) {
    if(a<=0&&b<=0) return 0;
    if(a>=0&&b>=0) return 2;
    if(a<=0&&b>=0) return 1;
    if(a>=0&&b<=0) return 3;
}
 
 
 
 
double distance (double x,double y,double x2,double y2)
{
    return sqrt(((x-x2)*(x-x2)+(y-y2)*(y-y2)));
}
 
 
 
 
 
const double pi = 3.14159265359 ;
int main()
{
#ifndef ONLINE_JUDGE
//    #define cin in
//    ifstream in("input.txt");
#endif // ONLINE_JUDGE
 
    int n;
    double x,y;
    cin>>n>>x>>y;
    double rMin = -1, rMax = -1;
    double pondezMesBelettes[4]={-1};
    vector<pair<int,int> > v(n);
    for(int c=0;c<n;c++) {
        double a,b;
        cin>>a>>b;
        v[c]=make_pair(a,b);
        double r = sqrt((x-a)*(x-a)+(y-b)*(y-b));
        double hi = x-a;
        double han = y-b;
        pondezMesBelettes[belette(hi,han)]=max(r,pondezMesBelettes[belette(hi,han)]);
        if(rMin==-1 || rMin > r)
            rMin = r;
        rMax = max(rMax,r);
    }
    for(int c=0;c<n;c++) {
            double machinx=v[(c+1)%v.size()].first-v[c].first;
            double machiny=v[(c+1)%v.size()].second-v[c].second;
            double d = distance(v[(c+1)%v.size()].first,v[(c+1)%v.size()].second,v[c].first,v[c].second);
            double r = ((x-v[c].first)*machinx+(y-v[c].second)*machiny)/d;
            double r2 = abs(((x-v[c].first)*(-machiny)+(y-v[c].second)*machinx)/d);
            if(r > d || r < 0) continue;
 
            if(rMin==-1 || rMin > r2)
                rMin = r2;
            rMax = max(rMax,r2);
    }
    double area1 = M_PI*rMax*rMax, area2 = M_PI*rMin*rMin;
    double res = area1-area2;
 
    cout<<fixed<<setprecision(12)<<area1-area2;
}