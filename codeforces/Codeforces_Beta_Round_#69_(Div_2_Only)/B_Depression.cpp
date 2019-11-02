#include <cstdio>
    using namespace std;
 
    int main()
    {
        int a,b;
    scanf("%d:%d",&a,&b);
        printf("%f %f",((float)(a%12))*(360.0/12.0)+((float)(b%60))*(360.0/(12.0*60.0)),((float)(b%60))*(360.0/60.0));
    }