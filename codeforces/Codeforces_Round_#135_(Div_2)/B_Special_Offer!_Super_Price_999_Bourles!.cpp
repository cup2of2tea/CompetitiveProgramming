#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <ctime>
#define FOREACH(i, n) for (typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
#define MEMSET(p, c) memset(p, c, sizeof(p))
#define LOG(n) log(n)/log(10)
using namespace std;
 
 
int main()
{
#ifndef ONLINE_JUDGE
#define cin in
    ifstream in("input.txt");
#endif
    long long d,p;
    cin>>d>>p;
    if(static_cast<int>(LOG(d))!=static_cast<int>(LOG(d+1)))
    {
            cout<<d;
            return 0;
    }
    long long mini=d-p;
    if(static_cast<int>(LOG(d))!=static_cast<int>(LOG(mini)))
    {
        for(int c=9;c>=0;c--)
        {
            long long z=pow((long double)10,static_cast<int>(LOG(d)))-1+pow((long double)10,static_cast<int>(LOG(d)))*c;
            if(z<=d&&z>=mini)
            {
                cout<<z;
                return 0;
            }
        }
        cout<<pow((long double)10,static_cast<int>(LOG(d)))-1;
        return 0;
    }
    long long int d2=d;
    int res=0;
    while(d2%10==9)
        res+=1,d2/=10;
    d2=d;
    long long mini2=mini;
    int degre_max=0;
    int degre=0;
    while(mini2!=0&&d2!=0)
    {
        if(mini2%10!=d2%10)
            degre_max=degre;
        degre++;
        mini2/=10;
        d2/=10;
    }
 
    if(degre_max<=res)
    {
        cout<<d;
        return 0;
    }
    string res2="";
    for(int c=0;c<degre_max;c++)
        res2='9'+res2,mini/=10,d/=10;
    if(d!=0)
    {
        res2=(char)((d%10-1)+'0')+res2;
        mini/=10;
    }
    while(mini!=0)
        res2=(char)(mini%10+'0')+res2,mini/=10;
    cout<<res2;
 
}