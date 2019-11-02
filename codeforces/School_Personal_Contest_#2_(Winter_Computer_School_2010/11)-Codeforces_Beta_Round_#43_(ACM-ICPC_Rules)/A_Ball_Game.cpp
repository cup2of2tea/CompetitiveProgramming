#include <cstdio>
 
int main()
{
    int n;
    scanf("%d",&n);
    int total=0;
    for(int c=1;c<n;c++)
    {
        total=(total+c)%n;
        printf("%d ",total+1);
    }
}