#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
 
 
using namespace std;
 
int main()
{
#ifndef ONLINE_JUDGE
    #define cin in
    ifstream in("input.txt");
#endif // ONLINE_JUDGE
 
    int n,m;
    cin>>n>>m;
    int act=1;
    long long int res=0;
    for(int c=0;c<m;c++)
    {
        int new_act;
        int z;
        cin>>new_act;
        z=new_act;
        if(z<act)
            z+=n;
        res+=z-act;
        act=new_act;
    }
    cout<<res;
}