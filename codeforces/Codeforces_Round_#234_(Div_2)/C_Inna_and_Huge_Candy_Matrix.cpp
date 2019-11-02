#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <iterator>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
 
 
pair<int,int> rotate1(pair<int,int> p,int &n,int &m)
{
    swap(n,m);
    return make_pair(p.second,m-p.first+1);
}
 
pair<int,int> rotate2(pair<int,int> p,int &n,int &m)
{
    for(int c=0;c<3;c++)
    {
        p = rotate1(p,n,m);
    }
    return p;
}
 
 
pair<int,int> symetry(pair<int,int> p,int &n,int &m)
{
    return make_pair(p.first,m-p.second+1);
}
 
 
int main()
{
    ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    #define cin in
    ifstream in("input.txt");
#endif // ONLINE_JUDGE
    int n,m,x,y,z;
    cin>>n>>m>>x>>y>>z;
    x%=4;
    y%=2;
    z%=4;
    int p;
    cin>>p;
    int nor = n, mor = m;
    for(int c=0;c<p;c++)
    {
        pair<int,int> point;
        cin>>point.first>>point.second;
        for(int c2=0;c2<x;c2++) point = rotate1(point,n,m);
        for(int c2=0;c2<y;c2++) point = symetry(point,n,m);
        for(int c2=0;c2<z;c2++) point = rotate2(point,n,m);
        n = nor, m =mor;
        cout<<point.first<<" "<<point.second<<endl;
    }
}