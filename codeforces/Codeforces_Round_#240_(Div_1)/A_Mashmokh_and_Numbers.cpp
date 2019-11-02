#include <iostream>
#include <queue>
using namespace std;
 
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    if(n==1)
    {
        if(k==0)
        {
            cout<<42;
        }
        else cout<<-1;
        return 0;
    }
    vector<int> res;
    int c;
    int act = 1;
    k-=(n-2)/2;
    if(k<=0)
    {
        cout<<-1;
        return 0;
    }
    for(c=0;c+3<n;c+=2)
    {
        while(act==k||(act+1)==k||act==2*k||(act+1)==2*k) act++;
        res.push_back(act);
        res.push_back(act+1);
        act+=2;
    }
    res.push_back(k);
    res.push_back(k*2);
    c+=2;
    if(c<n)
    {
        res.push_back(900000000);
    }
    for(int c=0;c<res.size();c++) cout<<res[c]<<" ";
}