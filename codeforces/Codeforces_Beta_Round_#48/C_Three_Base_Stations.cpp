#include <cstdio>
#include <algorithm>
using namespace std;
 
int n,a[200000],ans[3];
 
bool gao(int m){
    for(int i=0,x=0;i<3;i++){
        x=upper_bound(a,a+n,a[ans[i]=x]+m)-a;
        if(x==n) return true;
    }
    return false;
}
 
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n);
    int lo=0,hi=1000000000;
    while(lo<hi){
        int m=(lo+hi)/2;
        if(gao(m)) hi=m; else lo=m+1;
    }
    gao(lo);
    printf("%d.%d\n",lo/2,lo%2*5);
    for(int i=0;i<3;i++) printf("%d.%d ",a[ans[i]]+lo/2,lo%2*5);
    puts("");
}