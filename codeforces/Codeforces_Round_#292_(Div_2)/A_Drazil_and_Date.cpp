#include <iostream>
#include <random>
#include <utility>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <set>
#include <fstream>
using namespace std;
 
 
 
int main()
{
    ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    #define cin in
    ifstream in("input.txt");
#endif // ONLINE_JUDGE
    long long int a,b,s;
    cin>>a>>b>>s;
    if(abs(a)+abs(b)>s)
    {
        cout<<"No";
    }
    else if((s-(abs(a)+abs(b)))%2==1)
    {
        cout<<"No";
    }
    else
    {
        cout<<"Yes";
    }
}