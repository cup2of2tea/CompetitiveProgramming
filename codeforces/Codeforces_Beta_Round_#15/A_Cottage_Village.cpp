# include <iostream>
# include <cmath>
# include <algorithm>
using namespace std;
 
struct sq{
    int x, a;
}s[1024];
 
int cmp(sq c, sq b){
    return c.x<b.x;
}
 
int main(){
    
    int i, n, t;
    long long ans=0;
    double d;
    cin>>n>>t;
    for(i=0;i<n;i++)
        cin>>s[i].x>>s[i].a;
    sort(s, s+n,cmp);
    for(i=0;i<n-1;i++){
        d=(s[i+1].x-s[i+1].a/2.0)-(s[i].x+s[i].a/2.0);
        if(d>(double)t)
            ans+=2;
        else if(abs(d-(double)t)<0.000001)
            ans++;
    }
    ans+=2;
    cout<<ans;
    return 0;
}