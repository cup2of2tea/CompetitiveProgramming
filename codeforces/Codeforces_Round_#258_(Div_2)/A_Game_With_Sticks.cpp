#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <fstream>
#include <iostream>
#include <queue>
using namespace std;
 
 
 
int main()
{
    int n,m;
    cin>>n>>m;
    cout<<(min(n,m)%2==0?"Malvika":"Akshat");
}