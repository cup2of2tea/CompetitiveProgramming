#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <ctime>
#include <iterator>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
 
 
 
int main()
{
ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
//#define cin in
    ifstream in("input.txt");
#endif // ONLINE_JUDGE
    int n,m;
    cin>>n>>m;
    int c;
    for(c=0;n>0;c++)
    {
        n--;
        if((c+1)%m==0&&c>0) n++;
    }
    cout<<c;
}