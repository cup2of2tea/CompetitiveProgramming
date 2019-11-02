#include <bits/stdc++.h>
using namespace std;
 
const long long mod = 1e9+7;
 
long long pgcd(long long a, long long b) {
    if(a==0) return b;
    return pgcd(b%a,a);
}
 
long long ppcm(long long a, long long b) {
    return a*b/pgcd(a,b);
}
 
int main(){
    ios_base::sync_with_stdio(false);
    long long n,p,w,d;
    cin>>n>>p>>w>>d;
 
    long long pcm = ppcm(w,d);
 
    long long int c;
    for(c=0;c<w+1;c++) {
        long long tmp = c*d;
        if((p-tmp) % w == 0) {
            break;
        }
        if(c==w) {
            cout<<-1;
            return 0;
        }
    }
 
    long long int refer = (p-c*d);
 
 
    long long x1 = refer/w;
    long long y1 = (p-x1*w)/d;
 
    if(x1>=0&&y1>=0&&x1 + y1 <= n) {
        cout<<x1<<" "<<y1<<" "<<n-x1-y1<<endl;
        return 0;
    }
 
    refer %= pcm;
    x1 = refer/w;
    y1 = (p-x1*w)/d;
 
    if(x1>=0&&y1>=0&&x1 + y1 <= n) {
        cout<<x1<<" "<<y1<<" "<<n-x1-y1<<endl;
        return 0;
    }
 
    refer = refer + ((long long)(p-refer)/pcm)*pcm;
    x1 = refer/w;
    y1 = (p-x1*w)/d;
 
    if(x1>=0&&y1>=0&&x1 + y1 <= n) {
        cout<<x1<<" "<<y1<<" "<<n-x1-y1<<endl;
        return 0;
    }
    cout<<-1;
}