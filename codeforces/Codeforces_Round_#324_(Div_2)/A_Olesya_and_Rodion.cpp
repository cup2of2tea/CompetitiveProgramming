#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <set>
#include <iterator>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <list>
#include <stack>
#include <limits.h>
#define ll long long
using namespace std;
 
 
 
int main()
{
    ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    //#define cin in
    ifstream in("input.txt");
#endif // ONLINE_JUDGE
    int act = 1;
    int n,t;
    cin>>n>>t;
    if(n==1 && t ==10)
    {
        cout<<-1;
        return 0;
    }
    if(n==1) {
        cout<<t;
        return 0;
    }
 
    if(n==2){
        for(int c=10;c<100;c++)
        {
            if(c%t == 0){
                cout<<c;
                return 0;
            }
        }
    }
    if(t==10) {
        cout<<1;
        for(int c=1;c<n;c++)
        {
            cout<<0;
        }
        return 0;
    }
    for(int c=1;c<n;c++)
    {
        act*=10;
        act%=t;
    }
    int suffix = 0;
    for(int c2=0;c2<=20;c2++)
    {
        if((act+c2)%t==0)
        {
            if(n>2){
                cout<<1;
                for(int c3=0;c3<n-2;c3++){
                    cout<<0;
                }
            }
            cout<<c2<<endl;
            return 0;
        }
    }
}