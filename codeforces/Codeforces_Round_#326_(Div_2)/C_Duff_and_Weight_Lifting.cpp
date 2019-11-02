#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdio>
using namespace std;
 
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    scanf("%d",&n);
    vector<long long int> count(1e6+1000,0);
    for(int c=0;c<n;c++){
        int z;
        scanf(" %d",&z);
        count[z]++;
    }
    int res = 0;
    for(int c=0;c<count.size();c++)
    {
        if(count[c]&1) res++;
        if(count[c] > 1){
            long long int mapow = 2;
            for(int c2=1;mapow <= count[c]; c2++)
            {
                if(mapow & count[c]) {
                    count[c2+c]++;
                }
                mapow*=2;
            }
        }
    }
    printf("%d",res);
    return 0;
}