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
 
int main()
{
    ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    #define cin in
    ifstream in("input.txt");
#endif // ONLINE_JUDGE
    double x1,y1,x2,y2;
    double r;
    cin>>r>>x1>>y1>>x2>>y2;
    double d =sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    double nSteps = ceil(d/(2.*r));
    cout<<(int)(nSteps);
}