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
#define cin in
    ifstream in("input.txt");
#endif // ONLINE_JUDGE
    string s;
    cin>>s;
    int z = 0;
    int z2 = 0;
    for(int c=0;c<s.size();c++)
    {
        z *= 10;
        z +=(s[c]-'0');
        z %= 4;
    }
    if(z == 0) cout<<4;
    else if(z==1) cout<<0;
    else if(z==2) cout<<0;
    else if(z==3) cout<<0;
 
}