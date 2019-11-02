#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
 
using namespace std;
 
 
int main()
{
    int n;
    cin>>n;
    vector<int> sum(n,0);
    int sum_tot=0;
    for(int c=0;c<n;c++)
    {
        int z;
        cin>>z;
        sum[c]=z+(c>0?sum[c-1]:0);
        sum_tot+=z;
    }
    int res=0;
    if(sum_tot%2==0)
        for(int c=0;c<n-1;c++)
            if(sum_tot/2==sum[c])
                res++;
    cout<<res<<endl;
}
    