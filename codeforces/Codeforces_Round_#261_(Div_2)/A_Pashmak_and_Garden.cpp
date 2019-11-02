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
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    if(x1==x2)
    {
        cout<<x1+abs(y1-y2)<<" "<<y2<<" "<<x1+abs(y1-y2)<<" "<<y1<<endl;
    }
    else if(y1==y2)
    {
        cout<<x1<<" "<<y2+abs(x1-x2)<<" "<<x2<<" "<<y1+abs(x1-x2)<<endl;
    }
    else
    {
        if(abs(y1-y2)!=abs(x1-x2))
        {
            cout<<-1;
        }
        else
        {
            cout<<x1<<" "<<y2<<" "<<x2<<" "<<y1;
        }
    }
}