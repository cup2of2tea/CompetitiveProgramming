#include<cmath>
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
using namespace std;
#define ll __int64
int a[4],n[100000];
char c[100000];
int main()
{
    while(~scanf("%d%d%d%d",a,a+1,a+2,a+3))
    {
        int f=1,t=0;
        while(1)
        {
            if(a[0]==1&&a[1]==1&&a[2]==1&&a[3]==1)break;
            int can=0;
            for(int i=0;i<4;i++)
            {
                int j=(i+1)%4;
                if(a[i]%2==0&&a[j]%2==0)
                {
                    a[i]>>=1;
                    a[j]>>=1;
                    c[t]='/';
                    n[t++]=i;
                    can=1;
                    break;
                }
            }
            if(can)continue;
            int x=rand()%4;
            int y=(x+1)%4;
            a[x]++;a[y]++;
            c[t]='+';
            n[t++]=x;
        }
        for(int i=0;i<t;i++)
        printf("%c%d\n",c[i],n[i]+1);
    }
}